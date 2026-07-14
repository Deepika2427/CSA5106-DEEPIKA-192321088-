#include <stdio.h>

int main() {
    char cipher[1000];
    char plain[1000];
    char key[256] = {0};

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    /* Example mappings from frequency analysis */
    key['5']='A';
    key['‡']='G';
    key['†']='O';
    key['3']='D';

    int i;
    for(i=0; cipher[i]!='\0'; i++) {
        if(key[(unsigned char)cipher[i]])
            plain[i] = key[(unsigned char)cipher[i]];
        else
            plain[i] = cipher[i];
    }
    plain[i] = '\0';

    printf("Decrypted text:\n%s", plain);

    return 0;
}
