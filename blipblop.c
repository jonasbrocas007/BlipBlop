#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int interpreter(){
    #define Max_lines 10000
    #define Max_len 4 + 1
    int incrementer = 0;

    int line = 0;
    char data[Max_lines][Max_len];

    FILE *fblop;

    fblop = fopen("blipblop.txt", "r");
    if (fblop == NULL){
        printf("YOU ARE DONE, YOU ARE GONE, FLY YOU FOOL, FLY! \n");
        return 1;
    }
    
    while(!feof(fblop) && !ferror(fblop)){
        if (fgets(data[line], Max_len, fblop) != NULL)
            line++;
    }

    fclose(fblop);

    for(int i = 0; i < line; i++){
        if(strcmp(data[i], "blip") == 0){
            incrementer++;
        }
        if(strcmp(data[i], "blop") == 0){
            incrementer--;
        }

        if(strcmp(data[i], "glop") == 0){
            char asciiprint = incrementer;
            printf("%c", asciiprint);
        }
        if(strcmp(data[i], "plop") == 0){
            printf("%s","\n");
        }
        
    }
    return 0;
}

int deinterpreter(char *string, int Max_letters){

    //take a string
    //see the value of every letter
    //if newline then write plop
    //make incrementer and write the letter when matches with glop

    int printdiff;
    FILE *fblop;
    fblop = fopen("blipblop.txt", "w");


    for(int i = 0; i < Max_letters; i++){
        //printf("%d", string[i]);

        if(i == 0){ //print the first number
            for(int a = 0; a < string[0]; a++){
                fprintf(fblop, "blip\n");
            }
            fprintf(fblop, "glop\n");
        }

        if(i > 0){
            int printdiff = string[i] - string[i - 1];
            //printf("%d", printdiff);

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



int main(){
    char destring[3] = "ABC";
    deinterpreter(destring, 3);
    interpreter();
    return 0;
}