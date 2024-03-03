// cd C:\Users\aryam\OneDrive\Documents\C Codes\projects\hangman
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
	char randomword[1000], temp[50];  //randomword is the random word we read from that we read from the
	char word[1000]; //word is the variable that holds the string
	char output[50]; //output tells us whether the character is right or wrong
	int attempts=5; //this defines the maximum number of attempts a user has
	int counter=0, position=0, winner, length, i, match; 
	char alphabetfromuser; //the character that the user inputs

	int randomlineno, total_lines=0;
	int current_line=0;
	
	
	
	
	FILE *fp;   //line 19-40 is for reading the input
	fp=fopen("words.txt", "r");
	
	while(fgets(randomword, sizeof word, fp)!=NULL){
		total_lines++;
	}
	
	srand(time(NULL));
	randomlineno=rand()%total_lines+1;
	
	rewind(fp);
	
	while(fgets(randomword, sizeof word, fp)!=NULL){
		current_line++; 	
		if(current_line==randomlineno){
			strcpy(word,randomword);
		}
	}
	fclose(fp);
	
	int attempt=5; //wa=wrong attempt, used for the number of times it gets the word

	printf("%s\n", word);
	
	while (attempt != 0) {
        printf("Enter any alphabet in lowercase\n");
        fflush(stdout);
        scanf(" %c", &alphabetfromuser);
        getchar(); 
        
        for (int i = 0; i < strlen(word); i++) {
        int found = 0; 
            if (word[i] == alphabetfromuser) {
                printf("Yes, it's right!");
				printf("Position: %d\n", i + 1); 
                found = 1;
				counter++;
            }
        }
        
        if (!found) {
            printf("No, it's wrong\n");
            attempt--;
            printf("Attempts left: %d\n", attempt);
        }
		
		if(counter==(strlen(word)-1)){
			printf("Congrats, you guessed the word");
			break;
		}
		
        if (attempt == 0) {
            printf("Sorry, game over\n");
            break;
        }
    }
}	