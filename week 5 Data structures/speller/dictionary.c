// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

void printTable(int i);
char* toLowerCase(const char* str);
int amountOfWords = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //check if word is in dictionary
    int index = hash(word);
    if (table[index] != NULL) {
        return true;
//        if (strcasecmp(table[index]->word, word) == 0) {
//            return true;
//        }
//        else {
//            node *temp = table[index];
//            while (temp->next != NULL) {
//                if (strcasecmp(temp->next->word, word) == 0) {
//                    return true;
//                }
//                temp = temp->next;
//            }
//        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 0;
    int i = 0;
    char * temp  = toLowerCase(word);
    while (temp[i] != '\0') {
        hash_value = (hash_value * 31) + temp[i];
        i++;
    }

    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char buffer[LENGTH+1];
    FILE *file = fopen(dictionary, "r");
    if(file == NULL){
        printf("Could not open file...\n");
        return false;
    }

    while (fscanf(file, "%s", buffer) == 1) {
        int index = hash(buffer);
        //insert node into hash table
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            printf("Could not allocate memory...\n");
            return false;
        }
        strcpy(n->word, buffer);
        n->next = NULL;
        if(table[index] == NULL){
            table[index] = n;
        }
        else{
            n->next = table[index];
            table[index] = n;
        }
        amountOfWords++;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return amountOfWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++) {
        if (table[i] != NULL) {
            node *temp = table[i];
            while (temp != NULL) {
                node *temp2 = temp;
                temp = temp->next;
                free(temp2);
            }
        }
    }
    return true;
}

void printTable(int index){
    if(index > -1){
        if (table[index] != NULL) {
            printf("%i: ", index);
            printf("%s - ", table[index]->word);
            node *temp = table[index];
            while (temp->next != NULL) {
                printf("%s - ", temp->next->word);
                temp = temp->next;
            }
            printf("\n");
        }
    }else{

        for (int i = 0; i < N; i++) {
            if (table[i] != NULL) {
                printf("%i: ", i);
                printf("%s - ", table[i]->word);
                while (table[i]->next != NULL) {
                    printf("%s - ", table[i]->next->word);
                    table[i] = table[i]->next;
                }
                printf("\n");
            }
        }
    }
}

char* toLowerCase(const char* str) {
    char* temp = malloc(strlen(str) + 1);
    while (*str) {
        *temp = tolower(*str);
        str++;
    }
    return temp;
}
