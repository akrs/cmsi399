#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint8_t* parseHexString(char* txt, int txtlen) {
    uint8_t* result = malloc(txtlen);
    for (int i = 0; i < txtlen; ++i) {
        switch(txt[i]) {
            case 'a':
                result[i] += 0xa0;
                break;
            case 'b':
                result[i] += 0xb0;
                break;
            case 'c':
                result[i] += 0xc0;
                break;
            case 'd':
                result[i] += 0xd0;
                break;
            case 'e':
                result[i] += 0xe0;
                break;
            case 'f':
                result[i] += 0xf0;
                break;
            default:
                result[i] += (txt[i] - '0') * 16;
                break;
        }

        switch(txt[i + 1]) {
            case 'a':
                result[i] += 0x0a;
                break;
            case 'b':
                result[i] += 0x0b;
                break;
            case 'c':
                result[i] += 0x0c;
                break;
            case 'd':
                result[i] += 0x0d;
                break;
            case 'e':
                result[i] += 0x0e;
                break;
            case 'f':
                result[i] += 0x0f;
                break;
            default:
                result[i] += txt[i] - '0';
                break;
        }
    }

    return result;
}

void* hexto64(uint8_t *input, int input_length) {
    return 0;
}

int main(int argc, char const *argv[]) {

    char *input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    int input_length = 96;


    return 0;
}
