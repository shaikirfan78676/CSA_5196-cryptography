#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

void findPosition(char keySquare[SIZE][SIZE], char letter, int *row, int *col) {
    if (letter == 'J') {
        letter = 'I';  
    }

    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (keySquare[*row][*col] == letter) {
                return;
            }
        }
    }
}


void playfairDecrypt(char keySquare[SIZE][SIZE], char *cipherText, char *plainText) {
    int i;
    int row1, col1, row2, col2;

    for (i = 0; i < strlen(cipherText); i += 2) {
        
        findPosition(keySquare, cipherText[i], &row1, &col1);
        findPosition(keySquare, cipherText[i + 1], &row2, &col2);

        if (row1 == row2) {
            
            plainText[i] = (col1 == 0) ? keySquare[row1][SIZE - 1] : keySquare[row1][col1 - 1];
            plainText[i + 1] = (col2 == 0) ? keySquare[row2][SIZE - 1] : keySquare[row2][col2 - 1];
        } else if (col1 == col2) {
            
            plainText[i] = (row1 == 0) ? keySquare[SIZE - 1][col1] : keySquare[row1 - 1][col1];
            plainText[i + 1] = (row2 == 0) ? keySquare[SIZE - 1][col2] : keySquare[row2 - 1][col2];
        } else {
           
            plainText[i] = keySquare[row1][col2];
            plainText[i + 1] = keySquare[row2][col1];
        }
    }

    plainText[i] = '\0';
}

int main() {
    char keySquare[SIZE][SIZE] = {
        {'K', 'X', 'J', 'E', 'Y'},
        {'U', 'R', 'E', 'B', 'Z'},
        {'W', 'H', 'Y', 'T', 'U'},
        {'H', 'E', 'Y', 'F', 'S'},
        {'K', 'R', 'E', 'H', 'E'}
    };

    char cipherText[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char plainText[strlen(cipherText)];

    
    playfairDecrypt(keySquare, cipherText, plainText);

   
    printf("Decrypted Message: %s\n", plainText);

    return 0;
}
