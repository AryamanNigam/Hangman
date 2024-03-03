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
	
	printf("%s", word);