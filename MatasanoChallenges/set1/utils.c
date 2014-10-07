#include <stdlib.h>
#include <stdint.h>

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
    uint8_t* result = malloc(txtlen / 2 + 1);
    for (int posInInput = 0, posInResult = 0; posInInput < txtlen; posInInput += 2) {
        result[posInResult] += parseHexDigit(txt[posInInput]) * 0x10;
        result[posInResult++] += parseHexDigit(txt[posInInput + 1]);
    }
    return result;
}

char* hextoString(uint8_t* input, int input_length) {
    char convert[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char* result = malloc((input_length * 2) + 1);

    int posInResult = 0;
    for (int posInInput = 0; posInInput < input_length; ++posInInput) {
        result[posInResult++] = convert[input[posInInput] >> 4];
        result[posInResult++] = convert[input[posInInput] & 0xf];
    }

    result[posInResult] = 0x0;

    return result;
}
