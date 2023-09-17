#include <cs50.h>
#include <stdio.h>

// AMEX 378282246310005 15 digit start with 34 or 37
// Visa 4111111111111111 13 & 16 digit start with 4
// MasterCard 5105105105105100 16 digit start with 51, 52, 53, 54, or 55

void longToArray(long number, int arr[], int size) {
    int i = size - 1; // Start from the end of the array

    while (number > 0 && i >= 0) {
        arr[i] = number % 10; // Get the last digit
        number /= 10; // Remove the last digit
        i--;
    }
}

int leadingZeroIndex(int arr[], int size){
    for(int i = 0; i < size; i++){
        if(arr[i] != 0){
            return i;
        }
    }
    return 0;
}

int checkSum(int arr[], int size){
    int sum = 0;
    for(int i = size - 2; i >= 0; i -= 2){
        int digit = arr[i] * 2;
        if(digit > 9){
            sum += digit % 10;
            sum += digit / 10;
        } else {
            sum += digit;
        }
    }
    for(int i = size - 1; i >= 0; i -= 2){
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    long inputNumber = get_long("Number: ");
//     long inputNumber = 4003600000000014;
    int const sizeInput = 17;
    int inputNumberArray[sizeInput] = {0};
    string type = "INVALID";

    longToArray(inputNumber, inputNumberArray, sizeInput);

    int indexFirstDigit = leadingZeroIndex(inputNumberArray, sizeInput);
    int amountOfDigits = sizeInput - indexFirstDigit;
//     printf("Amount of digits: %i\n", amountOfDigits);

    int firstTwoDigits[2] = {inputNumberArray[indexFirstDigit], inputNumberArray[indexFirstDigit + 1]};


//     for(int i = 0; i < sizeInput; i++){
//         printf("%i", inputNumberArray[i]);
//     }

    if(amountOfDigits == 15 && (firstTwoDigits[1] == 4 || firstTwoDigits[1] == 7) && firstTwoDigits[0] == 3){
        type = "AMEX";
    } else if((amountOfDigits == 13 || amountOfDigits == 16) && inputNumberArray[indexFirstDigit] == 4){
        type = "VISA";
    } else if(amountOfDigits == 16 && firstTwoDigits[0] == 5 && (firstTwoDigits[1] == 1 || firstTwoDigits[1] == 2 || firstTwoDigits[1] == 3 || firstTwoDigits[1] == 4 || firstTwoDigits[1] == 5)){
        type = "MASTERCARD";
    }

    int check = checkSum(inputNumberArray, sizeInput);
//     printf("\nChecksum: %i\n", check);
    if(check % 10 != 0){
        type = "INVALID";
    }

    printf("%s\n", type);
}

