#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Max_lines 10000
#define Max_len 4 + 1
int incrementer = 0;

int main(void) {
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
        
    }
    return 0;
}