#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

uint8_t* xorHex(uint8_t* input, uint8_t* key, int len) {
    uint8_t *result = malloc((size_t)len);
    for (int i = 0; i < len; ++i) {
        result[i] = input[i] ^ key[i];
    }

    return result;
}

int main(int argc, char const *argv[]) {
    uint8_t* input = parseHexString("1c0111001f010100061a024b53535009181c", 36);
    uint8_t* key = parseHexString("686974207468652062756c6c277320657965", 36);
    uint8_t* result = xorHex(input, key, 36);

    printf("%s\n", hextoString(result, 18));

    free(result);
    return 0;
}
