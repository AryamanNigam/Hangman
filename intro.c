#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void hangmanart(int c) {
    if (c == 5) {
        printf("\n\n\t +-------------+  \n");
        printf("\t |             |  \n");
        printf("\t |             |  \n");
        printf("\t |             @  \n");
        printf("\t |  \n");
        printf("\t |  \n");
        printf("\t |  \n");
        printf("\t |  \n");
        printf("\t |  \n");
        printf("\t |________________  \n");
    }
    else if (c == 4) {
        printf("\n\n\t +-------------+  \n");
        printf("\t |             |  \n");
        printf("\t |             |  \n");
        printf("\t |             @  \n");
        printf("\t |             |  \n");
        printf("\t |             |  \n");
        printf("\t |               \n");
        printf("\t |               \n");
        printf("\t |  \n");
        printf("\t |________________  \n");
    }
    else if (c == 3) {
        printf("\n\n\t +-------------+  \n");
        printf("\t |             |  \n");
        printf("\t |             |  \n");
        printf("\t |             @  \n");
        printf("\t |             |  \n");
        printf("\t |             |  \n");
        printf("\t |            /    \n");
        printf("\t |  \n");
        printf("\t |  \n");
        printf("\t |________________  \n");
    }
    else if (c == 2) {
        printf("\n\n\t +-------------+  \n");
        printf("\t |             |  \n");
        printf("\t |             |  \n");
        printf("\t |             @  \n");
        printf("\t |             |  \n");
        printf("\t |             |  \n");
        printf("\t |            / \\  \n");
        printf("\t |  \n");
        printf("\t |  \n");
        printf("\t |________________  \n");
    }
    else if (c == 1) {
        printf("\n\n\t +-------------+ \n");
        printf("\t |             | \n");
        printf("\t |             | \n");
        printf("\t |             @ \n");
        printf("\t |            /|  \n");
        printf("\t |             |  \n");
        printf("\t |            / \\  \n");
        printf("\t |  \n");
        printf("\t |  \n");
        printf("\t |________________  \n");
    }
    else if (c == 0) {
        printf("\n\n\t +-------------+ \n");
        printf("\t |             | \n");
        printf("\t |             | \n");
        printf("\t |             @ \n");
        printf("\t |            /|\\  \n");
        printf("\t |             |  \n");
        printf("\t |            / \\  \n");
        printf("\t |  \n");
        printf("\t |  \n");
        printf("\t |________________  \n");
    }
}

int main() {
	char randomword[1000], temp[50];  //randomword is the random word we read from that we read from the
	char word[1000]; //word is the variable that holds the string
	char output[50]; //output tells us whether the character is right or wrong
	char alphabetfromuser; //the character that the user inputs
	int randomlineno, total_lines=0;
	int current_line=0;
	int attempt=6; //attempt, used for the number of times it gets the word
	int i=0;
	
	
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
		
	char format[strlen(word)];
	for(i=0; i<strlen(word); i++){
		format[i]='_';						
	}
	
	for(i=0; i<(strlen(word)-1); i++){
		printf("%c", format[i]);
	}
	
	while (attempt != 0) {
        printf("\n\n\t\tEnter any alphabet in lowercase\n\n");
        fflush(stdout);
        scanf(" %c", &alphabetfromuser);
        getchar(); 
        int found=0;
		int counter=0; 
		
        for (int i = 0; i < strlen(word); i++) { 
			if (word[i] == alphabetfromuser) {
                printf("\n\n\t\tYes, it's right!\n"); 
                found = 1;									
				format[i]=alphabetfromuser;					
            }
        }
        
		for(i=0; i<(strlen(word)-1); i++){
			printf("%c", format[i]);
		}
			
		for(i=0; i<(strlen(word)-1); i++){
			if(format[i]==word[i]){
				counter++;
			}
		}
        if (!found) {
            printf("\n\n\t\tNo, it's wrong\n");
            attempt--;
			hangmanart(attempt);
            printf("\t\tAttempts left: %d\n", attempt);
        }
		
		
		if(counter==(strlen(word)-1)){
			printf("\nCongrats, you guessed the word\n");
			break;
		}
		
        if (attempt == 0) {
            printf("\n\t\tSorry, game over\n");
            break;
        }
    }
}	