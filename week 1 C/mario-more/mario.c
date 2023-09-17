#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int piramidHeight = 0;

    while(piramidHeight < 1 || piramidHeight > 8){
        piramidHeight = get_int("Height: ");
    }

    int piramidWidth = piramidHeight * 2 + 2;

    for(int i = 0; i < piramidHeight; i++){
        int leftCenter = piramidHeight - 1;
        int rightCenter = piramidHeight + 2;
        int left[2] = {leftCenter - i, leftCenter};
        int right[2] = {rightCenter, rightCenter + i};

        for(int j = 0; j < piramidWidth; j++){
            if(j >= left[0] && j <= left[1] || j >= right[0] && j <= right[1]){
                printf("#");
            } else {
                if(j > right[1]){
                    break;
                }
                printf(" ");
            }
        }
        printf("\n");
    }
    
}