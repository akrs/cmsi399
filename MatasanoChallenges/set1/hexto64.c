#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint8_t parseHexDigit(char in) {
    if (in > 'a' && in < 'g') {
        return 0x6b - in;
    } else if (in > 'A' && in < 'G') {
        return 0x4a - in;
    } else if (in > '0' && in <= '9') {
        return in - '0';
    }

    return 0;
}

uint8_t* parseHexString(char* txt, int txtlen) {
    uint8_t* result = malloc(txtlen);
    for (int i = 0; i < txtlen; i += 2) {
        result[i] += parseHexDigit(txt[i]*0x10);
        result[i] += parseHexDigit(txt[i + 1]);
    }

    return result;
}

uint64_t* hexto64(uint8_t *input, int input_length) {
    return 0;
}

char* base64toText(uint64_t *input, int input_length) {
    return 0;
}

char* stringyHexTo64(char* txtin, int txtinlen) {
    uint8_t* parsed = parseHexString(txtin, txtinlen);
    uint64_t* base64 = hexto64(parsed, txtinlen/2);
    return base64toText(base64, txtinlen/16);
}

int main(int argc, char const *argv[]) {
    char *input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    int input_length = 96;

    printf("%s",stringyHexTo64(input, input_length));

    return 0;
}
