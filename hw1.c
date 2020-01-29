// Kim Merchant
// Assignment 1: Diamond
// Create a diamond of characters with a user-specified number of lines

#include <stdio.h>

int askUser() {
    int userNum;
    printf("Enter non-negative, odd integer n: ");
    scanf("%d", &userNum);
    if (userNum <= 0 || userNum % 2 == 0) {
        printf("Error: ");
        askUser();
    }
    else return userNum;
}

void addSpaces(int spc) {
    for (int i = 0; i < spc; i++) {
        printf(" ");
    }
}

void addSymbol(char sym, int number) {
    for (int i = 0; i < number; i++) {
        printf("%c", sym);
    }
    printf("\n");
}

int main() {
    char symbols[] = "!@#$\%^&*-/\\=)(~`\";:?";
    int number = askUser();
    int spaces = number / 2;
    int quantity = 1;
    
    for (int i = 0; i < number; i++) {
        int sym = i % 20;
        addSpaces(spaces);
        addSymbol(symbols[sym], quantity);
        if (i < number / 2) {
            spaces--;
            quantity = quantity + 2;
        } else {
            spaces++;
            quantity = quantity - 2;
        }
    }
}

