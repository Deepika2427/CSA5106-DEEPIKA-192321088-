#include <stdio.h>
#include <ctype.h>

int main() {
    char ct[1000];
    int a_inv = 9, b = 15;

    printf("Enter ciphertext: ");
    scanf("%s", ct);

    printf("Plaintext: ");

    for(int i = 0; ct[i]; i++) {
        if(isupper(ct[i])) {
            int c = ct[i] - 'A';
            int p = (a_inv * (c - b + 26)) % 26;
            printf("%c", p + 'A');
        }
    }
    return 0;
}
