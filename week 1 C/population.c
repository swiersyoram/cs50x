#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize = 0;
    int startSizeLimit = 9;
    int currentSize = 0;
    int endSize = 0;
    int years = 0;

   while(startSize < startSizeLimit){
    startSize = get_int("Start size: ");
   }

    while(endSize < startSize){
       endSize = get_int("End size: ");
    }

    currentSize = startSize;

    while(currentSize < endSize){
        currentSize = currentSize + (currentSize / 3) - (currentSize / 4);
        years++;
    }

    printf("Years: %d\n", years);
  }
