#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VICTORY 6
#define DRAW 3
#define DEFEAT 0

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main(void) {

    system("clear");

    FILE *filePtr;
    filePtr = fopen("input.txt","r");
    if(filePtr==NULL) {
        printf("File pointer is null.\n");
        return 1;
    }

    // A for Rock, B for Paper, and C for Scissors. 
    // X for Rock, Y for Paper, and Z for Scissors.

    char p1,p2;
    int score = 0;
    int newScore = 0;
    while(1) {
        p1 = fgetc(filePtr);
        fgetc(filePtr);
        p2 = fgetc(filePtr);
        fgetc(filePtr);
        if(p1==-1) break;

        switch (p1)
        {
        case 'A':   //ROCK
            switch (p2)
            {
            case 'X':   //ROCK      //LOSE
                score += DRAW + ROCK; 
                newScore += DEFEAT + SCISSORS; 
                break;
            case 'Y':   //PAPER     //DRAW
                score += VICTORY + PAPER; 
                newScore += DRAW + ROCK; 
                break;
            case 'Z':   //SCISSORS  //WIN
                score += DEFEAT + SCISSORS; 
                newScore += VICTORY + PAPER; 
                break;
            }
            break;
        case 'B':   //PAPER
            switch (p2)
            {
            case 'X':   //ROCK
                score += DEFEAT + ROCK; 
                newScore += DEFEAT + ROCK; 
                break;
            case 'Y':   //PAPER
                score += DRAW + PAPER;
                newScore += DRAW + PAPER; 
                break;
            case 'Z':   //SCISSORS
                score += VICTORY + SCISSORS; 
                newScore += VICTORY + SCISSORS; 
                break;
            }
            break;
        case 'C':   //SCISSORS
            switch (p2)
            {
            case 'X':   //ROCK
                score += VICTORY + ROCK; 
                newScore += DEFEAT + PAPER; 
                break;
            case 'Y':   //PAPER
                score += DEFEAT + PAPER; 
                newScore += DRAW + SCISSORS; 
                break;
            case 'Z':   //SCISSORS
                score += DRAW + SCISSORS; 
                newScore += VICTORY + ROCK; 
                break;
            }            
            break;
        }

    }

    fclose(filePtr);
    printf("Total score : %i\n",score);
    printf("Total new score : %i\n",newScore);
    

    return 0;
}