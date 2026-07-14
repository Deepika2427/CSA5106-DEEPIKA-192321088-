#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];


void findPosition(char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main() {
    char key[] = "MONARCHY";
    char alphabet[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    char used[26] = {0};
    char plaintext[100], prepared[100], cipher[100];
    int i, j, k = 0, len;

    
    int idx = 0;
    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J')
            ch = 'I';
        if (!used[ch - 'A']) {
            matrix[idx / 5][idx % 5] = ch;
            used[ch - 'A'] = 1;
            idx++;
        }
    }

    for (i = 0; alphabet[i] != '\0'; i++) {
        char ch = alphabet[i];
        if (!used[ch - 'A']) {
            matrix[idx / 5][idx % 5] = ch;
            used[ch - 'A'] = 1;
            idx++;
        }
    }

    printf("Playfair Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    printf("\nEnter Plaintext: ");
    scanf("%s", plaintext);

   
    len = strlen(plaintext);
    k = 0;
    for (i = 0; i < len; i++) {
        char ch = toupper(plaintext[i]);
        if (ch == 'J')
            ch = 'I';
        prepared[k++] = ch;
    }

    if (k % 2 != 0)
        prepared[k++] = 'X';
    prepared[k] = '\0';

   
    for (i = 0; i < k; i += 2) {
        int r1, c1, r2, c2;
        findPosition(prepared[i], &r1, &c1);
        findPosition(prepared[i + 1], &r2, &c2);

        if (r1 == r2) {
            cipher[i] = matrix[r1][(c1 + 1) % 5];
            cipher[i + 1] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2) {
            cipher[i] = matrix[(r1 + 1) % 5][c1];
            cipher[i + 1] = matrix[(r2 + 1) % 5][c2];
        }
        else {
            cipher[i] = matrix[r1][c2];
            cipher[i + 1] = matrix[r2][c1];
        }
    }

    cipher[k] = '\0';

    printf("\nEncrypted Text: %s\n", cipher);

    return 0;
}
