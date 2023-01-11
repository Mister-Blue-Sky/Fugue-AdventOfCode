#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10

int main(void) {

    system("clear");

    FILE *filePtr;
    filePtr = fopen("input.txt","r");
    if(filePtr==NULL) {
        printf("File pointer is null.\n");
        return 1;
    }

    // Day1

    char line[MAX_LINE_LENGTH];
    int maxCal = -1;
    int maxThreeCal[] = {0,0,0};
    int currentCal = 0;
    while(fgets(line, MAX_LINE_LENGTH, filePtr)) {
        if(strcmp(line,"\n")==0) {

            if(currentCal > maxThreeCal[0]) {
                maxThreeCal[2] = maxThreeCal[1];                
                maxThreeCal[1] = maxThreeCal[0];
                maxThreeCal[0] = currentCal;
            }else if(currentCal > maxThreeCal[1]) {
                maxThreeCal[2] = maxThreeCal[1];                
                maxThreeCal[1] = currentCal;
            } else if (currentCal > maxThreeCal[2]) {
                maxThreeCal[2] = currentCal;                
            }
            if(currentCal > maxCal) {
                maxCal = currentCal;
            }
            currentCal = 0;
        } else {
            currentCal += atoi(line);
        }
    }

    fclose(filePtr);
    printf("Maxcal : %i\n",maxCal);
    printf("MaxThreeCal : %i\n",maxThreeCal[0]+maxThreeCal[1]+maxThreeCal[2]);
    

    return 0;
}