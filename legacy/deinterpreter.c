#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Max_letters 6

//take a string
//see the value of every letter
//if newline then write plop
//make incrementer and write the letter when matches with glop
char string[Max_letters] = "ABA\nA";
char blip[4] = "blip";

int printdiff;

int main(){
    FILE *fblop;
    fblop = fopen("blipblop.txt", "w");


    for(int i = 0; i < Max_letters; i++){
        printf("%d", string[i]);

        if(i == 0){ //print the first number
            for(int a = 0; a < string[0]; a++){
                fprintf(fblop, "blip\n");
            }
            fprintf(fblop, "glop\n");
        }

        if(i > 0){
            int printdiff = string[i] - string[i - 1];
            printf("%d", printdiff);

            if(printdiff == 0){
                fprintf(fblop, "glop\n");
            }

            if(printdiff > 0){
                for(int b = 0; b < printdiff; b++){
                    fprintf(fblop, "blip\n");
                }
                fprintf(fblop, "glop\n");
            }

            if(printdiff < 0){
                for(int c = 0; c > printdiff; c--){
                    fprintf(fblop, "blop\n");
                }
                fprintf(fblop, "glop\n");
            }

        }

        if(string[1] == 10){
            fprintf(fblop, "plop\n");
        }

    }
    fclose(fblop);
    return 0;
}