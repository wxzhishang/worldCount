#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 114514 

int count_characters(FILE* file);
int count_words(FILE* file);

int main() {
    char param[3]; 
    char file_name[MAX]; 
    scanf("%s %s", param, file_name);

    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error£¡\n");
        
        return 1;
    }
    else if (strcmp(param, "-c") == 0) {
        int char_count = count_characters(file);
        
        printf("×Ö·ûÊý£º%d\n", char_count);
    }
    else if (strcmp(param, "-w") == 0) {
        int word_count = count_words(file);
        
        printf("µ¥´ÊÊý£º%d\n", word_count);
    }

    fclose(file);

    return 0;
}

int count_characters(FILE* file) {
    int char_count = 0; 
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        char_count++;
    }

    return char_count;
}

int count_words(FILE* file) {
    int word_count = 0;
    int flag = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == ',') {
            flag = 0;
        }
        else if (flag == 0) {
            flag = 1;
            word_count++;
        }
    }

    return word_count;
}
