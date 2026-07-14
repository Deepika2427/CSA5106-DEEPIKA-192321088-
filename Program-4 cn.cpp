#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], key[100], ciphertext[100];
    int i, j = 0;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key: ");
    scanf("%s", key);

    int keyLen = strlen(key);

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            int shift = toupper(key[j % keyLen]) - 'A';

            if (isupper(plaintext[i]))
                ciphertext[i] = ((plaintext[i] - 'A' + shift) % 26) + 'A';
            else
                ciphertext[i] = ((plaintext[i] - 'a' + shift) % 26) + 'a';

            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';

    printf("\nCiphertext: %s\n", ciphertext);

    return 0;
}
