#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint8_t parseHexDigit(char in) {
    if (in > 'a' && in < 'g') {
        return in - 'a' + 0xA;
    } else if (in > 'A' && in < 'G') {
        return in - 'A' + 0xA;
    } else if (in > '0' && in <= '9') {
        return in - '0';
    }

    return 0;
}

uint8_t* parseHexString(char* txt, int txtlen) {
    printf("I'm parsing hex.\n");
    uint8_t* result = malloc(txtlen / 2);
    for (int posInInput, posInResult = 0; posInInput < txtlen; posInInput += 2) {
        result[posInResult] += parseHexDigit(txt[posInInput]) * 0x10;
        result[posInResult++] += parseHexDigit(txt[posInInput + 1]);
    }
    printf("I've finished parsing hex.\n");
    return result;
}

char* base64toText(uint8_t *input, int input_length) {
    char convert[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};
    char *result = malloc((size_t)(input_length / 1.5 + 1));
    printf("I just allocated memory. Gonna convert this.\n");
    int posInResult = 0;
    int posInInput = 0;
    printf("Setup some loop variables.\n");
    while (posInInput + 2 < input_length) {
        printf("I'm in ur loop, converting ur stuff.\n");
        uint8_t toConvert = input[posInInput] >> 2;
        printf("The number I'm converting is: %d\n", toConvert);
        result[posInResult++] = convert[toConvert];
        printf("I got: %c, from %d\n", convert[toConvert], toConvert);
        toConvert = ((input[posInInput] & 0x3) << 4) + (input[posInInput + 1] >> 4); // Grab the rightmost two bits of this position and the leftmost two bits of the next.
        posInInput++;
        printf("The number I'm converting is: %d\n", toConvert);
        result[posInResult++] = convert[toConvert];
        printf("I got: %c, from %d\n", convert[toConvert], toConvert);
        toConvert = (input[posInInput] & 0xff << 2) + (input[posInInput + 1] >> 6);
        posInInput++;
        printf("The number I'm converting is: %d\n", toConvert);
        result[posInResult++] = convert[toConvert];
        printf("I got: %c, from %d\n", convert[toConvert], toConvert);
        toConvert = input[posInInput] & 0x3f;
        result[posInResult++] = convert[toConvert];
        printf("The number I'm converting is: %d\n", toConvert);
        printf("I got: %c, from %d\n", convert[toConvert], toConvert);
    }

    result[posInResult] = 0x0;

    printf("%s\n", result);
    return result;
}

char* stringyHexTo64(char* txtin, int txtinlen) {
    printf("I'm trying to convert.\n");
    uint8_t *parsed = parseHexString(txtin, txtinlen);
    printf("I have some parsed data.\n");
    char *result = base64toText(parsed, txtinlen / 2);
    free(parsed);
    return result;
}

int main(int argc, char const *argv[]) {
    char *input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    printf("%s\n", "Just setup input. I have not died yet.");
    int input_length = 96;
    char *result = stringyHexTo64(input, input_length);

    printf("Finished converting.\n");

    printf("%s\n", result);

    free(result);


    return 0;
}
