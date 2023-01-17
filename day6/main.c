#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#define MAX_LINE_LENGTH 64
#define NB_STACKS 10
#define MAX_CRATES 64

int main(void) {

    system("clear");

    FILE *filePtr;
    filePtr = fopen("input.txt","r");
    if(filePtr==NULL) {
        printf("File pointer is null.\n");
        return 1;
    }

    // Day6

    int table[26] = {0};

    // char c[4] = {'a','a','a','a'};
    char memory[14];
    int index = 0;
    bool end = false;
    while(!end) {
        index++;

        char tmp = fgetc(filePtr)-97;
        if(index>14) {
            table[memory[index%14]]--;
            end = true;
        }
        memory[index%14] = tmp;
        table[tmp]++;
        if(index<=14) continue;

        for(int i=0; i<26; i++) if(table[i]>1) end=false;


        // c[0] = c[1];
        // c[1] = c[2];
        // c[2] = c[3];
        // c[3] = fgetc(filePtr);

        // char cc = fgetc(filePtr);
        // cc = 'a';
        // printf("%i\n",cc);


        // break;

        // bool b = 
        // c[0]==c[1] || c[0]==c[2] || c[0]==c[3] ||
        // c[1]==c[2] || c[1]==c[3] ||
        // c[2]==c[3];

        // printf("%c%c%c%c\n",c[0],c[1],c[2],c[3]);

        // if(index>3 && !b) break;
        if(index==4096) break;
    }
    

        for(int i=0; i<26; i++) printf("%c:%i\n",(char)i+97,table[i]);

    
    
    

    fclose(filePtr);
    printf("Emplacement : %i\n",index);
    
    return 0;
}