#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint8_t parseHexDigit(char in) {
    if (in > 'a' && in < 'g') {
        return 'a' - in;
    } else if (in > 'A' && in < 'G') {
        return 'A' - in;
    } else if (in > '0' && in <= '9') {
        return in - '0';
    }

    return 0;
}

uint8_t* parseHexString(char* txt, int txtlen) {
    uint8_t* result = malloc(txtlen / 2);
    printf("%s\n", "Started parsing. I have not died yet.");
    for (int posInInput, posInResult = 0; posInInput < txtlen; posInInput += 2) {
        result[posInResult] += parseHexDigit(txt[posInInput]) * 0x10;
        result[posInResult++] += parseHexDigit(txt[posInInput + 1]);
        printf("Parsed %c%c as %x\n", txt[posInInput], txt[posInInput+1], result[posInResult - 1]);
    }

    return result;
}

char* base64toText(uint8_t *input, int input_length) {
    char convert[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};
    char *result = malloc((size_t)(input_length / 1.5 + 1));
    int posInInput, posInResult = 0;
    for (posInInput = 0; posInInput + 2 <= input_length; posInInput += 3) {
        uint8_t toConvert = input[posInInput] / 0x4;
        printf("Converting: %d\nRaw hex for position %d: %x\n", toConvert, posInInput, input[posInInput]);
        result[posInResult++] = convert[toConvert];
        toConvert = (input[posInInput] % 0x4) * 0x10 + input[++posInInput] / 0x10;
        printf("Converting: %d\nRaw hex for position %d: %x\n", toConvert, posInInput, input[posInInput]);
        result[posInResult++] = convert[toConvert];
        toConvert = input[posInInput] % 0x10 + input[++posInInput] / 0x40;
        printf("Converting: %d\nRaw hex for position %d: %x\n", toConvert, posInInput, input[posInInput]);
        result[posInResult++] = convert[toConvert];
        toConvert = input[posInInput] % 0x40;
        printf("Converting: %d\nRaw hex for position %d: %x\n", toConvert, posInInput, input[posInInput]);
        result[posInResult] = convert[toConvert];
    }

    result[posInResult] = 0x0;

    printf("%s\n", result);
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
    printf("%s\n", "Just setup input. I have not died yet.");
    int input_length = 96;
    char* result = stringyHexTo64(input, input_length);

    printf("%s\n",result);

    free(result);

    return 0;
}
