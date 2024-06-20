#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool is_blank(string text);
int letters(string text);
int sentences(string text);
int words(string text);

int main(void){

    // Pede um texto ao usuário e o armazena na variável text
    string text = "";
    do{
        text = get_string("Text: ");
    }while(strlen(text) == 0 || text == NULL || is_blank(text));

    // Calcular quantas letras e sentencas existem em 100 palavras
    float L = (float)letters(text) / words(text) * 100;
    float S = (float)sentences(text) / words(text) * 100;

    // Calcula o índice de Coleman-Liau
    float indice = 0.0588 * L - 0.296 * S - 15.8;

    // Arredonda o índice
    int grade = round(indice);

    // Determina a grade que deve exibir na saída
    if(grade < 1){
        printf("Before Grade 1\n");
    }else if(grade >= 16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %i\n", grade);
    }
}

// verificando se a primeira letra da string é um espaço em branco
bool is_blank(string text){
    if(isspace(text[0])){
        return 1;
    }
    return 0;
}

// calcula quantas letras há no texto
int letters(string text){
    int count = 0;
    for(int i = 0; i < strlen(text); i++){
        if(isalpha(text[i])){
            count++;
        }
    }
    return count;
}

// calcula quantas palavras há no texto
int words(string text){
    int count = 1;
    for(int i = 0; i < strlen(text); i++){
        if(isspace(text[i])){
            count++;
        }
    }
    return count;
}

// calcula quantas sentenças há no texto
int sentences(string text){
    int count = 0;
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            count++;
        }
    }
    return count;
}
