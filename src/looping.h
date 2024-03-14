void readfromfile(char randomword[1000], char word[1000], int *total_lines, int *current_line, int *randomlineno){
	FILE *fp;  
	fp=fopen("words.txt", "r");
	
	while(fgets(randomword, 1000, fp)!=NULL){
		(*total_lines)++;
	}
	
	srand(time(NULL));
	*randomlineno=rand()%(*total_lines)+1;
	
	rewind(fp);
	
	while(fgets(randomword, 1000, fp)!=NULL){
		(*current_line)++; 	
		if((*current_line)==(*randomlineno)){
			strcpy(word,randomword);
		}
	}
	fclose(fp);
}