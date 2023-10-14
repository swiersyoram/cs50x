#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int validateKey(string key);
char * getCypherText(char * text, string  key);
char * stringToCharArray(string text);
char * keyToUpperCase(char * key);


int main(int argc, string argv[])
{
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = keyToUpperCase(argv[1]);
    printf("key: %s\n", key);
    if(validateKey(key) == 1){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    char * text = stringToCharArray(get_string("plaintext: "));
//    printf("plaintext: %s\n", text);
    string cypherText = getCypherText(text, key);
    printf("ciphertext: %s\n", cypherText);
}

char* stringToCharArray(string text){
    unsigned long textLength = strlen(text);
    char * arr = malloc(textLength * sizeof(char));
    for(int i = 0; i < textLength; i++){
        arr[i] = text[i];
    }
    return arr;
}

int validateKey(string key){
    unsigned long keyLength = strlen(key);
    if(keyLength != 26){
        return 1;
    }
    for(int i = 0; i < keyLength; i++){
        if(key[i] < 'A' || key[i] > 'z' || key[i] > 'Z' && key[i] < 'a'){
            return 1;
        }
        for(int j = i + 1; j < keyLength; j++){
            if(key[i] == key[j]){
                return 1;
            }
        }
    }
    return 0;
}

char * keyToUpperCase(char * key){
    unsigned long keyLength = strlen(key);
    char * upperCaseKey = malloc(keyLength * sizeof(char));
    for(int i = 0; i < keyLength; i++){
        if(key[i] >= 'a' && key[i] <= 'z'){
            upperCaseKey[i] = key[i] - 32;
        }else{
            upperCaseKey[i] = key[i];
        }
    }
    return upperCaseKey;
}



char * getCypherText(char * text, string key){
    unsigned long textLength = strlen(text);
    for(int i = 0; i < (int)textLength; i++){
        char c = text[i];
        if(c >= 'A' && c <= 'Z'){
            text[i] = key[c - 'A'];
        }
        if(c >= 'a' && c <= 'z'){
            text[i] = key[c - 'a']+32;
        }
    }
    return text;

}
