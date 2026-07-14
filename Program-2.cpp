#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], ciphertext[100];
    char key[27];
    int i;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the 26-letter substitution key:\n");
    printf("(Example: QWERTYUIOPASDFGHJKLZXCVBNM)\n");
    scanf("%s", key);

    // Encrypt the plaintext
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isupper(plaintext[i])) {
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i])) {
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }
        else {
            ciphertext[i] = plaintext[i]; // Keep spaces and symbols unchanged
        }
    }

    ciphertext[i] = '\0';

    printf("\nCiphertext: %s\n", ciphertext);

    return 0;
}
