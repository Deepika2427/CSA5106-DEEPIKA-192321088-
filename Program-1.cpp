#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    int k, i;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key (1-25): ");
    scanf("%d", &k);

    if (k < 1 || k > 25) {
        printf("Invalid key! Please enter a value between 1 and 25.\n");
        return 1;
    }

    // Encrypt the message
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            text[i] = ((text[i] - 'A' + k) % 26) + 'A';
        } else if (islower(text[i])) {
            text[i] = ((text[i] - 'a' + k) % 26) + 'a';
        }
        // Non-alphabet characters remain unchanged
    }

    printf("Encrypted message: %s", text);

    return 0;
}
