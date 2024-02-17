#include <stdio.h>
#include <string.h>

const char* ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

char encrypt(char plaintext, char key) {
    int char_index = strchr(ALPHABET, plaintext) - ALPHABET;
    int key_index = strchr(ALPHABET, key) - ALPHABET;
    return ALPHABET[(char_index + key_index) % 52];
}

char decrypt(char ciphertext, char key) {
    int char_index = strchr(ALPHABET, ciphertext) - ALPHABET;
    int key_index = strchr(ALPHABET, key) - ALPHABET;
    return ALPHABET[(char_index - key_index + 52) % 52];
}

void encryptText(char *plaintext, char *key, char *encrypted_text) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        encrypted_text[i] = encrypt(plaintext[i], key[i % strlen(key)]);
    }
    encrypted_text[i] = '\0';
}

void decryptText(char *ciphertext, char *key, char *decrypted_text) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        decrypted_text[i] = decrypt(ciphertext[i], key[i % strlen(key)]);
    }
    decrypted_text[i] = '\0';
}

int main() {
    char key[] = "VeryImportantCompanySecretsThatShouldNeverBeRevealed";
    char plaintext[] = "Enter something here";
    char encrypted_text[100];
    char decrypted_text[100];

    // Encryption
    encryptText(plaintext, key, encrypted_text);
    printf("Encrypted: %s\n", encrypted_text);

    // Decryption
    decryptText(plaintext, key, decrypted_text);
    printf("Decrypted: %s\n", decrypted_text);

    return 0;
}
