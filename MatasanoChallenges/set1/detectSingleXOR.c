#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"
#define NUMBER_OF_MESSAGES  327
#define MESSAGE_LENGTH      60

/* Designed to read from stdin, do not want to figure out reading of
   a buffer with arbitrary length. */
int main(int argc, char const *argv[]) {
    uint8_t* possibleMessages[NUMBER_OF_MESSAGES];
    char* string = malloc(MESSAGE_LENGTH);
    double bestScore = -INFINITY;
    int bestMessage = 0;
    for (int i = 0; i < NUMBER_OF_MESSAGES; ++i) {  // Grab message strings
        scanf("%s", string);
        possibleMessages[i] = parseHexString(string, MESSAGE_LENGTH);
        double score = scoreSingleXOR(possibleMessages[i], MESSAGE_LENGTH / 2);
        printf("Score at point %d is %f for string: %s\n", i, score, breakSingleXOR(possibleMessages[i], MESSAGE_LENGTH / 2));
        if (score > bestScore) {
            bestScore = score;
            bestMessage = i;
        }
    }

    char* message = breakSingleXOR(possibleMessages[bestMessage], MESSAGE_LENGTH / 2);

    printf("Best message: %d, Score: %f, Message: %s\n", bestMessage, bestScore, message);

    return 0;
}
