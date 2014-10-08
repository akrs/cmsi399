#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <smmintrin.h>
#include "utils.h"

int main(int argc, char const *argv[]) {
    uint8_t* input = parseHexString("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736", 68);
    int inputlen = 34;

    char* message = breakSingleXOR(input, inputlen);

    printf("Message: %s\n", message);
    free(message);

    return 0;
}
