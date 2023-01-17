#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#define MAX_LINE_LENGTH 64
#define NB_STACKS 10
#define MAX_CRATES 64

void push(char stacks[NB_STACKS][MAX_CRATES], int tops[NB_STACKS], int stackId, char item) {
    tops[stackId]++;
    stacks[stackId][tops[stackId]] = item;
    return;
}

char pull(char stacks[NB_STACKS][MAX_CRATES], int tops[NB_STACKS], int stackId) {
    tops[stackId]--;
    return stacks[stackId][tops[stackId]+1];
}

void move(char stacks[NB_STACKS][MAX_CRATES], int tops[NB_STACKS], int nb, int s1, int s2) {
    for(int i=0; i<nb; i++) {
        push(stacks,tops,s2,pull(stacks,tops,s1));
    }
}

void move9001(char stacks[NB_STACKS][MAX_CRATES], int tops[NB_STACKS], int nb, int s1, int s2) {
    for(int i=0; i<nb; i++) {
        push(stacks,tops,9,pull(stacks,tops,s1));
    }
    for(int i=0; i<nb; i++) {
        push(stacks,tops,s2,pull(stacks,tops,9));
    }
}


void flipStacks(char stacks[NB_STACKS][MAX_CRATES], int tops[NB_STACKS]) {
    for(int i=0; i<NB_STACKS; i++) {
        int top = tops[i];
        int middle = top/2;
        for(int j=0; j<=middle; j++) {
            char temp = stacks[i][j];
            stacks[i][j] = stacks[i][top-j];
            stacks[i][top-j] = temp;
        }
    }
}

void displayStacks(char stacks[NB_STACKS][MAX_CRATES],int tops[NB_STACKS]) {
    printf("\n");
    for(int i=MAX_CRATES-1; i>=0; i--) {
        for(int j=0; j<NB_STACKS; j++) {
            if(i<=tops[j]) printf("[%c] ",stacks[j][i]);
            else printf("[ ] ");
        }
        printf("\n");
    }
    for(int i=0; i<NB_STACKS; i++) printf(".%i. ",tops[i]);
    printf("\n");
    printf(" 1   2   3   4   5   6   7   8   9 \n");
    printf("\n");
}

int main(void) {

    system("clear");

    FILE *filePtr;
    filePtr = fopen("input.txt","r");
    if(filePtr==NULL) {
        printf("File pointer is null.\n");
        return 1;
    }

    // Day5

    // Initialize the data structure
    char stacks[NB_STACKS][MAX_CRATES];
    int tops[NB_STACKS];
    for(int i=0; i<MAX_CRATES; i++) {
        for(int j=0; j<NB_STACKS; j++) {
            stacks[j][i] = '-';
        }
    }
    for(int i=0; i<NB_STACKS; i++) tops[i]=-1;


    // Fill the initial stacks
    char line[MAX_LINE_LENGTH];
    while(fgets(line,MAX_LINE_LENGTH,filePtr)) {
        if(line[1]=='1')break;
        printf("%s",line);
        
        for(int s=0; s<NB_STACKS-1; s++) {
            if(line[1+s*4]==' ') continue;
            push(stacks,tops,s,line[1+s*4]);
        }
    }
    flipStacks(stacks,tops);
    displayStacks(stacks,tops);
    // printf("Pull : [%c]\n",pull(stacks,tops,8));
    // displayStacks(stacks,tops);
    // push(stacks,tops,7,pull(stacks,tops,8));
    
    // displayStacks(stacks,tops);
    // printf("move");
    // move(stacks,tops,5,4-1,1-1);
    // displayStacks(stacks,tops);


    // Apply crate movements
    int tmp = 0;

    fgets(line,MAX_LINE_LENGTH,filePtr);
    while(fgets(line,MAX_LINE_LENGTH,filePtr)) {
        printf("Line : %s",line);
        int nb,s1,s2;
        char temp[MAX_LINE_LENGTH];
        
        sscanf(strtok(line," "), "%s", temp);
        sscanf(strtok(NULL," "), "%i", &nb);
        sscanf(strtok(NULL," "), "%s", temp);
        sscanf(strtok(NULL," "), "%i", &s1);
        sscanf(strtok(NULL," "), "%s", temp);
        sscanf(strtok(NULL," "), "%i", &s2);

        // move(stacks,tops,nb,s1-1,s2-1);
        move9001(stacks,tops,nb,s1-1,s2-1);
        displayStacks(stacks,tops);


        // if(tmp++ == 15) break;
    }

    displayStacks(stacks,tops);

    for(int i=0; i<NB_STACKS; i++) printf("%c",stacks[i][tops[i]]);






    
    
    

    fclose(filePtr);
    // printf("Total number of concerned pairs : %i\n",nbPairs);
    
    return 0;
}