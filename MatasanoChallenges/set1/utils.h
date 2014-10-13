uint8_t parseHexDigit(char in);

/* You have to free the result */
uint8_t* parseHexString(char* txt, int txtlen);

/* You have to free the result */
char* hextoString(uint8_t* input, int input_length);

/* You have to free the result */
uint8_t* xorSingleValue(uint8_t* input, int inputlen, uint8_t key);

/* THIS KILLS THE RESULT BUFFER. You have been warned. */
void xorSingleValueInPlace(uint8_t* input, int inputlen, uint8_t key, uint8_t* result);

/* Higher is better, 1 is perfect. */
double score(char* input, int inputlen);

/* Breaks a single char XOR, based on english letter frequency */
char* breakSingleXOR(uint8_t* input, int inputlen);

/* Scores a single XORed string based on letter frequency after best guess of key */
double scoreSingleXOR(uint8_t* input, int inputlen);

