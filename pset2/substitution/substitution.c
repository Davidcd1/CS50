#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

bool isValid(string text);
bool isBlank(string text);
string encrypt(string text, string key);

int main(int argc, char *argv[]){
    string key = "";

    // Checks if the key is valid
    if(argc == 2 && isValid(argv[1])){
        key = argv[1];
    }else{
        printf("Type a valid key!\n");
        return 1;
    }

    // Asks the user for a text and checks if it is valid
    string plaintext = "";
    do{
        plaintext = get_string("plaintext: ");
    }while(isBlank(plaintext));

    // Encrypts the text
    string encryptedtext = encrypt(plaintext, key);

    // Displays text on the screen
    if(encryptedtext != NULL){
        printf("ciphertext: %s\n", encryptedtext);
        free(encryptedtext);
    }

    return 0;

}

// Checks if the key is valid
bool isValid(string text){
    int len = strlen(text);
    if(len != 26){
        return false;
    }else{
        char repeat[26] = {0};
        for(int i = 0; i < len; i++){
            if(!isalpha(text[i])){
                return false;
            }else{
                for(int j = 0; j < i; j++){
                    if(text[i] == repeat[j]){
                        return false;
                    }
                }
                repeat[i] = text[i];
            }
        }
    }
    return true;
}

// Checks if it is valid
bool isBlank(string text){
    if(strlen(text) == 0 || text == NULL || isspace(text[0])){
        return true;
    }else{
        return false;
    }
}

// Encrypts the text
string encrypt(string text, string key){
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int len = strlen(text);
    char *encrypted_text = malloc((len+1) * sizeof(char));
    for(int i = 0; i < len; i++){
        if(!isalpha(text[i])){
            encrypted_text[i] = text[i];
        }else{
            for(int j = 0; j < 26; j++){
                if(text[i] == alpha[j] || text[i] == alpha[j] - 32){
                    if(isupper(text[i])){
                        if(isupper(key[j])){
                            encrypted_text[i] = key[j];
                        }else{
                            encrypted_text[i] = key[j] - 32;
                        }
                    }else{
                        if(isupper(key[j])){
                            encrypted_text[i] = key[j] + 32;
                        }else{
                            encrypted_text[i] = key[j];
                        }
                    }
                }
            }
        }
    }
    encrypted_text[len] = '\0';
    return encrypted_text;
}
