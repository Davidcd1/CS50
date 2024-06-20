#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool isValid(int c, char v[]);
bool is_blank(string text);
string cipher(string text, int key);

int main(int argc, char *argv[]){
    // checks if N is valid
    int key = 0;
    if(!isValid(argc, argv[1])){
        return 1;
    }else{
        key = atoi(argv[1]);
    }

    // asks the user for text and checks if it is blank
    string plaintext = "";
    do{
        plaintext = get_string("plaintext: ");
    }while(is_blank(plaintext));

    // encrypts the text requested from the user
    string ciphertext = cipher(plaintext, key);

    // display text on the screen
    if(ciphertext != NULL){
        printf("ciphertext: %s\n", ciphertext);
        free(ciphertext);
    }

    return 0;
}

bool isValid(int c, char v[]){
    if(c == 2){
        for(int i = 0; i < strlen(v); i++){
            if(!isdigit(v[i])){
                printf("Key must be a valid positive integer\n");
                return false;
            }
        }
        return true;
    }else{
        printf("Use: ./caesar key\n");
        return false;
    }
}

bool is_blank(string text){
    if(strlen(text) == 0 || text == NULL){
        return false;
    }else if(!isspace(text[0])){
        return false;
    }else{
        return true;
    }
}

string cipher(string text, int key){
    int len = strlen(text);
    char *ciphertext = malloc((len+1) * sizeof(char));
    if (ciphertext == NULL){
        return NULL;
    }

    for(int i = 0; i < len; i++){
        if(!isalpha(text[i])){
            ciphertext[i] = text[i];
        }else{
            if(isupper(text[i])){
                ciphertext[i] = (((text[i] - 'A') + key) % 26) + 'A';
            }else if(islower(text[i])){
                ciphertext[i] = (((text[i] - 'a') + key) % 26) + 'a';
            }
        }
    }
    ciphertext[len] = '\0';
    return ciphertext;
}
