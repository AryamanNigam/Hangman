void get_word(char random_word[1000], char file_name[1000]){
	char word[1000];	
	int current_line;
	int random_line_no;
	
    FILE *fp;  
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    int total_lines = 0; 
    char line[1000]; 
    while (fgets(line, sizeof(line), fp) != NULL) {
        (total_lines)++;
    }
    
    srand(time(NULL));
    random_line_no = rand() % (total_lines) + 1;
    
    rewind(fp);
    
    current_line = 0;
    
    while (fgets(random_word, 1000, fp) != NULL) {
        (current_line)++; 
        if ((current_line) == (random_line_no)) {
            strcpy(word, random_word);
            break;
        }
    }
    
    fclose(fp);
}