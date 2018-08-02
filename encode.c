/*
 * encode.c
 *  This program encodes morse code into an integers with 0 being equal to a
 * dot (.) and 1 being equal to a dash (-) and then decodes the integer into an
 * English character.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char get_ascii_from_morse(int);

char morse_alphabet[237];

int main() {
    morse_alphabet[17] = 'E';
    morse_alphabet[25] = 'T';
    morse_alphabet[34] = 'I';
    morse_alphabet[42] = 'A';
    morse_alphabet[50] = 'N';
    morse_alphabet[58] = 'M';
    morse_alphabet[67] = 'S';
    morse_alphabet[75] = 'U';
    morse_alphabet[83] = 'R';
    morse_alphabet[91] = 'W';
    morse_alphabet[99] = 'D';
    morse_alphabet[107] = 'K';
    morse_alphabet[115] = 'G';
    morse_alphabet[123] = 'O';
    morse_alphabet[132] = 'H';
    morse_alphabet[140] = 'V';
    morse_alphabet[148] = 'F';
    morse_alphabet[164] = 'L';
    morse_alphabet[180] = 'P';
    morse_alphabet[188] = 'J';
    morse_alphabet[196] = 'B';
    morse_alphabet[204] = 'X';
    morse_alphabet[212] = 'C';
    morse_alphabet[220] = 'Y';
    morse_alphabet[228] = 'Z';
    morse_alphabet[236] = 'Q';

    unsigned int letter;
    char input;

    /**********
     * Clock  *
     **********/

    // clock_t start, end;
    // double cpu_time_used;

    // start = clock();
    // char morse_letter = get_ascii_from_morse(228);
    // end = clock();

    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("time: 0%.6f\n", cpu_time_used);
    /**********
     *        *
     **********/

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    while(1) {
        letter = 1;
        char count = 0;
        while((input = getchar()) == '-' || input == '.') {
            if(input == '-') {
                letter <<= 1;
                letter += 1;
                count++;
            }
            if(input == '.') {
                letter <<= 1;
                count++;
            }
            //printf("l1: %d\n", letter);
            // printf("cnt: %d\n", count);
            // printf("l2: %d\n", (letter << 3));
            // printf("l2: %d\n", letter);
        }
        letter = (letter << 3) + (count & 0b111);

        char morse_letter = get_ascii_from_morse(letter);

        printf("\n%c\n", morse_letter);
    }
}

char get_ascii_from_morse(int letter) {
    printf("c: %d\n", letter);
    return morse_alphabet[letter];
}