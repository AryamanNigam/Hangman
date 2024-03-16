void read_from_file(char rando_word[1000], char word[1000], int *total_lines, int *current_line, int *random_line_no, char file_name[1000]){
    FILE *fp;  
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
 
    srand(time(NULL));
    *random_line_no = rand() % (*total_lines) + 1;
    
    rewind(fp);
    
    *current_line = 0;
    
    while (fgets(rando_word, 1000, fp) != NULL) {
        (*current_line)++; 
        if ((*current_line) == (*random_line_no)) {
            strcpy(word, rando_word);
            break;
        }
    }
    
    fclose(fp);
}