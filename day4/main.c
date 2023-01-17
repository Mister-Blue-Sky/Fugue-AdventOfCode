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

    // Day4
    int nbPairs = 0;

    char line[MAX_LINE_LENGTH];
    while(fgets(line,MAX_LINE_LENGTH,filePtr)) {
        
        int a1,b1,a2,b2;
        sscanf(strtok(line,"-,"), "%i", &a1);
        sscanf(strtok(NULL,"-,"), "%i", &b1);
        sscanf(strtok(NULL,"-,"), "%i", &a2);
        sscanf(strtok(NULL,"-,"), "%i", &b2);

        if((b1>=a2 && a2>=a1) || (b2>=a1 && a2<=a1)) {
            nbPairs++;
            printf("%i-%i %i-%i\n",a1,b1,a2,b2);
        } 

    }

    fclose(filePtr);
    printf("Total number of concerned pairs : %i\n",nbPairs);
    
    return 0;
}