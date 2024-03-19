#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "get_random_word.h"
#include "hangmanart.h"

int main(int argc, char **argv) {
	char word[1000]; //word is the variable that holds the string
	char output[50]; //output tells us whether the character is right or wrong
	char alphabet_from_user; //the character that the user inputs
	int attempt=6; //attempt, used for the number of times it gets the word
	int i=0;
	char guessed[26]={0};
	
	get_word(word, argv[1]);
	
	printf("%s", word);
	
	char format[strlen(word)];
	
	for(i=0; i<strlen(word); i++){
		format[i]='_';						
	}
	
	for(i=0; i<(strlen(word)-1); i++){
		printf("%c", format[i]);
		printf(" ");
	}
	
	while (attempt != 0) {
        printf("\n\n\t\tEnter any alphabet\n\n");
        fflush(stdout);
        scanf(" %c", &alphabet_from_user);
        getchar(); 
		
		
		if(islower(alphabet_from_user)){
				alphabet_from_user=toupper(alphabet_from_user);
		}
		
		
		if(guessed[alphabet_from_user - 'A']) {
			printf("\n\n\t Letter has already been entered\n");
			continue;
		}
		
		guessed[alphabet_from_user- 'A']=1;
		
        int found=0;
		int counter=0; 
		
        for (int i = 0; i < strlen(word); i++) { 
			if (word[i] == alphabet_from_user) {
                printf("\n\n\t\tYes, it's right!\n"); 
                found = 1;									
				format[i]=alphabet_from_user;		
				guessed[i]=alphabet_from_user;
            }
        }
        
		for(i=0; i<(strlen(word)-1); i++){
			printf("%c", format[i]);
			printf(" ");
		}
			
		for(i=0; i<(strlen(word)-1); i++){
			if(format[i]==word[i]){
				counter++;
			}
		}
        if (!found) {
            printf("\n\n\t\tNo, it's  wrong\n");
            attempt--;
			hangman_art(attempt);
            printf("\t\tAttempts left: %d\n", attempt);
        }
		
		
		if(counter==(strlen(word)-1)){
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

