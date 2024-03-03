#include <stdio.h>
#include <string.h>

int main() {
	char str[100]; //creating a new array
	char substrings[10][10]; //creating substring array with first dimension is for number and second is for words
	int i, j, k, count;
	j = 0;
	count = 0;
	printf("Enter the string: \n");
	gets(str);
	printf("The required string is %s\n", str);
	for (i = 0; i <= strlen(str); i++) {
    if (str[i] == ' ' || str[i] == '\0') {
        substrings[count][j] = '\0';
        count++;
        j = 0;
    } 
	else {
        if (j < 9) {
            substrings[count][j] = str[i];
            j++;
        } else {
            // Handle error: word length exceeds the limit
            printf("Error: Word length exceeds the limit.\n");
            return 1; // or take appropriate action
        }
    }
}


	printf("String after splitting: \n");
	for(i=0; i<count; i++){
		printf("%s\n", substrings[i]);
	}
}