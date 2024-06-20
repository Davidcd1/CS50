#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int tamanho = 0;

    do
    {
        // pedindo armazenando o valor digitado pelo usuário
        tamanho = get_int("Tamanho: ");
    }
    // verificando se o valor é válido
    while (tamanho < 1 || tamanho > 8);

    // Cria as linhas da nossa piramide
    for (int linhas = 1; linhas <= tamanho; linhas++)
    {

        for (int espacos = tamanho - linhas; espacos > 0; espacos--)
        {
            printf(" ");
        }

        // Cria as colunas da nossa piramide
        for (int colunas = 0; colunas < linhas; colunas++)
        {
            // Cria os blocos
            printf("#");
        }
        printf("\n");
    }
}
