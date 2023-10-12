#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include "math.h"

int countLetters(char* text);
int countWords(char* text);
int countSentences(char* text);

int main(void)
{


    char* text = get_string("Text: ");

    int amountLetters = countLetters(text);
    int amountWords = countWords(text);
    int amountSentences = countSentences(text);

//    printf("Letters: %i\n", amountLetters);
//    printf("Words: %i\n", amountWords);
//    printf("Sentences: %i\n", amountSentences);

    float L = (float)amountLetters / (float)amountWords * 100;
    float S = (float)amountSentences / (float)amountWords * 100;
    double grade = 0.0588 * L - 0.296 * S - 15.8;
    printf("Grade %f\n", grade);
    if(grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if(grade >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    printf("Grade %i\n", (int)round(grade));


}

int countLetters(char* text) {
    int count = 0;
    int length = (int)strlen(text);
    for (int i = 0; i < length; i++) {
        if (text[i] >= 'A' && text[i] <= 'z') {
            count++;
            printf("%c", text[i]);
        }
        if(text[i]==' '){
            printf(" ");
        }
    }
    printf("\n");
    return count;
}

int countWords(char* text) {
    int count = 0;
    int length = (int)strlen(text);
    for (int i = 0; i < length; i++) {
        if (text[i] == ' ') {
            count++;
        }
    }
    return count+1;
}

int countSentences(char* text) {
    int count = 0;
    int length = (int)strlen(text);
    for (int i = 0; i < length; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    return count;
}