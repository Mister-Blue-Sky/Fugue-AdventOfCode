#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#define MAX_LINE_LENGTH 64

int main(void) {

    system("clear");

    FILE *filePtr;
    filePtr = fopen("input.txt","r");
    if(filePtr==NULL) {
        printf("File pointer is null.\n");
        return 1;
    }

    // Day3
    int somPriority = 0;
    int somPriorityGroup = 0;
    char line[MAX_LINE_LENGTH];

    while(fgets(line,MAX_LINE_LENGTH,filePtr)) {
        
        char size = strlen(line)-1;
        
        int signatureL[52] = {0};
        int signatureR[52] = {0};
        for(int i=0; i<size/2; i++) {
            char c = line[i];
            c = (c <= 'Z') ? c-'A'+26 : c-'A'-32;
            signatureL[c] = 1;
        }
        for(int i=size/2; i<size; i++) {
            char c = line[i];
            c = (c <= 'Z') ? c-'A'+26 : c-'A'-32;
            signatureR[c] = 1;
        }
        for(int i=0;i<52;i++) {
            if(signatureL[i]&signatureR[i]) {
                somPriority+=i+1;
                break;
            }
        }
    }

    rewind(filePtr);

    while(fgets(line,MAX_LINE_LENGTH,filePtr)) {
        char size = strlen(line)-1;        
        int signature1[52] = {0};
        for(int i=0; i<size; i++) {
            char c = line[i];
            c = (c <= 'Z') ? c-'A'+26 : c-'A'-32;
            signature1[c] = 1;
        }

        fgets(line,MAX_LINE_LENGTH,filePtr);
        size = strlen(line)-1;        
        int signature2[52] = {0};
        for(int i=0; i<size; i++) {
            char c = line[i];
            c = (c <= 'Z') ? c-'A'+26 : c-'A'-32;
            signature2[c] = 1;
        }

        fgets(line,MAX_LINE_LENGTH,filePtr);
        size = strlen(line)-1;        
        int signature3[52] = {0};
        for(int i=0; i<size; i++) {
            char c = line[i];
            c = (c <= 'Z') ? c-'A'+26 : c-'A'-32;
            signature3[c] = 1;
        }

        for(int i=0;i<52;i++) {
            if((signature1[i]&signature2[i])&signature3[i]) {
                somPriorityGroup+=i+1;
                break;
            }
        }
    }

    fclose(filePtr);
    printf("Total priority : %i\n",somPriority);
    printf("Total priority group : %i\n",somPriorityGroup);
    
    return 0;
}