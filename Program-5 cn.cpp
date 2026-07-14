#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    int a, b, i;

    printf("Enter plaintext (uppercase letters only): ");
    scanf("%s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    /* Check whether 'a' is valid */
    int valid = 0;
    int validA[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};

    for (i = 0; i < 12; i++) {
        if (a == validA[i]) {
            valid = 1;
            break;
        }
    }

    if (!valid) {
        printf("Invalid value of a! Encryption is not one-to-one.\n");
        return 0;
    }

    printf("Ciphertext: ");

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            int p = text[i] - 'A';
            int c = (a * p + b) % 26;
            printf("%c", c + 'A');
        } else if (islower(text[i])) {
            int p = text[i] - 'a';
            int c = (a * p + b) % 26;
            printf("%c", c + 'a');
        } else {
            printf("%c", text[i]);
        }
    }

    printf("\n");

    return 0;
}
