#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <smmintrin.h>
#include "utils.h"

char* breakSingleXOR(uint8_t* input, int inputlen) {
    uint8_t bestKey = 0;
    double bestKeyScore = 0;
    uint8_t* possibleMessage = malloc(inputlen);
    for (uint8_t possibleKey = 0; possibleKey < 0xff; possibleKey++) {
        xorSingleValueInPlace(input, inputlen, possibleKey, possibleMessage);
        double possibleKeyScore = score((char*)possibleMessage, inputlen);
        if (possibleKeyScore > bestKeyScore) {
            bestKey = possibleKey;
            bestKeyScore = possibleKeyScore;
        }
    }

    xorSingleValueInPlace(input, inputlen, bestKey, possibleMessage);

    return (char*)possibleMessage;
}

int main(int argc, char const *argv[]) {
    uint8_t* input = parseHexString("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736", 68);
    int inputlen = 34;

    char* message = breakSingleXOR(input, inputlen);

    printf("Message: %s\n", message);
    free(message);

    return 0;
}
