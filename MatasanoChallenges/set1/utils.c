#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define ISALPHA(c) ((c > 'a' & c < 'z') | ( c > 'A' & c < 'Z'))
#define TOLOWER(c) (( c > 'A' & c < 'Z') ? c + 0x20 : c)

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

char* hextoString(uint8_t* input, int inputlen) {
    char convert[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char* result = malloc((inputlen * 2) + 1);

    int posInResult = 0;
    for (int posInInput = 0; posInInput < inputlen; ++posInInput) {
        result[posInResult++] = convert[input[posInInput] >> 4];
        result[posInResult++] = convert[input[posInInput] & 0xf];
    }

    result[posInResult] = 0x0;

    return result;
}


uint8_t* xorSingleValue(uint8_t* input, int inputlen, uint8_t key) {
    uint8_t *result = malloc((size_t)inputlen);
    for (int i = 0; i < inputlen; ++i) {
        result[i] = input[i] ^ key;
    }

    return result;
}

void xorSingleValueInPlace(uint8_t* input, int inputlen, uint8_t key, uint8_t* result) {
    for (int i = 0; i < inputlen; ++i) {
        result[i] = input[i] ^ key;
    }
}

double score(char* input, int inputlen) {
    double idealFrequencies[] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074};
    double counts[24] = { 0 };
    for (int i = 0; i < inputlen; ++i) {
        char c = input[i];
        if (!ISALPHA(c)) continue;
        counts[(int)(TOLOWER(c) - 'a')]++;
    }

    double score = 1;
    for (int i = 0; i < 26; ++i) {
        score -= fabs((counts[i] / inputlen) - idealFrequencies[i]);
    }

    return score;
}
