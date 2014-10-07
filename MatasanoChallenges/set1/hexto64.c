#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint8_t parseHexDigit(char in);

uint8_t* parseHexString(char* txt, int txtlen);

char* base64toText(uint8_t *input, int input_length) {
    char convert[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};
    char *result = malloc((size_t)(input_length / 1.5 + 1));
    int posInResult = 0;
    int posInInput = 0;
    // This probably makes no sense. Check the chart here: http://en.wikipedia.org/wiki/Base64#Examples
    while (posInInput + 2 < input_length) {
        uint8_t toConvert = input[posInInput] >> 2;
        result[posInResult++] = convert[toConvert];

        toConvert = ((input[posInInput] & 0x3) << 4) + (input[posInInput + 1] >> 4);
        posInInput++;
        result[posInResult++] = convert[toConvert];     // Byte 2 of 3, character 2 of 4

        toConvert = ((input[posInInput] & 0xf) << 2) + (input[posInInput + 1] >> 6);
        posInInput++;
        result[posInResult++] = convert[toConvert];

        toConvert = input[posInInput] & 0x3f;
        result[posInResult++] = convert[toConvert];
        posInInput++;
    }

    result[posInResult] = 0x0;

    return result;
}

char* stringyHexTo64(char* txtin, int txtinlen) {
    uint8_t *parsed = parseHexString(txtin, txtinlen);
    char *result = base64toText(parsed, txtinlen / 2);
    free(parsed);
    return result;
}

int main(int argc, char const *argv[]) {
    char *input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    int input_length = 96;
    char *result = stringyHexTo64(input, input_length);

    printf("%s\n", result);

    free(result);

    return 0;
}
