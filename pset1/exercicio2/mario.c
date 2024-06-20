#include <stdio.h>
#include <cs50.h>

int main(void){

    int tamanho = 0;

    do{
        tamanho = get_int("Tamanho: ");
    }while(tamanho < 1 || tamanho > 8);

    for(int linhas = 0; linhas < tamanho; linhas++){

        for(int espacos = tamanho - linhas-1; espacos > 0; espacos--){
            printf(" ");
        }

        for(int colunas = 0; colunas <= linhas; colunas++){
            printf("#");
        }

        printf("  ");

        for(int colunas = 0; colunas <= linhas; colunas++){
            printf("#");
        }

        printf("\n");
    }



}
