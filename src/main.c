#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h> 
#include <time.h>
#include "get_random_word.h"
#include "hangmanart.h"

int main(int argc, char **argv) {
    char random_word[1000];
    char word[1000]; 
    char output[50]; 
    char alphabet_from_user; 
    int attempt = 6; 
    int i = 0;
    bool guessed[26] = {false}; 
    
    get_word(word, argv[1]);
	if(argc!=2){
		printf("\n\n\tYou forgot to enter the file.\n");
		return 1;
	}

    char format[strlen(word)];

    for (i = 0; i < strlen(word)-1; i++) {
        format[i] = '_';
    }
	format[i]='\0';

    for (i = 0; i < strlen(word); i++) {
        printf("%c ", format[i]);
    }

    while (attempt != 0) {
        printf("\n\n\t\tEnter any alphabet\n\n");
        fflush(stdout);
        scanf(" %c", &alphabet_from_user);
        getchar();

        if (islower(alphabet_from_user)) {
            alphabet_from_user = toupper(alphabet_from_user);
        }

        if (guessed[alphabet_from_user - '@']) {
            printf("\n\n\t Letter has already been entered\n");
            continue;
        }

        guessed[alphabet_from_user - '@'] = true;

        int found = 0;
        int counter = 0;

        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == alphabet_from_user) {
                printf("\n\n\t\tYes, it's right!\n");
                found = 1;
                format[i] = alphabet_from_user;
                guessed[i] = alphabet_from_user;
            }
        }

        for (i = 0; i < strlen(word); i++) {
            printf("%c ", format[i]);
        }

        for (i = 0; i < strlen(word); i++) {
            if (format[i] == word[i]) {
                counter++;
            }
        }
        if (!found) {
            printf("\n\n\t\tNo, it's  wrong\n");
            attempt--;
            hangman_art(attempt);
            printf("\t\tAttempts left: %d\n", attempt);
        }

        if (counter == strlen(word)) {
            printf("\nCongrats, you guessed the word\n");
            break;
        }

        if (attempt == 0) {
            printf("\n\t\tSorry, game over\n");
            printf("\n\n\t\tThe word was %s", word);
            break;
        }
    }
}
