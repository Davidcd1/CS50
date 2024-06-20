#include <stdio.h>
#include <cs50.h>

int main (void){

    int populacao = 0, populacao_des = 0;

    do
    {
        populacao = get_int("População Atual: ");
    }while(populacao < 9);

    do
    {
        populacao_des = get_int("Populacao Desejada: ");
    }while(populacao_des < populacao);

    int anos = 0;
    int populacao_atual = populacao;
    int natalidade = populacao/3;
    int mortalidade = populacao/4;

    if(populacao == populacao_des || populacao_des < populacao+natalidade-mortalidade){
        populacao_des = 0;
    }

    while(populacao_atual < populacao_des){
        natalidade = populacao_atual/3;
        mortalidade = populacao_atual/4;

        populacao_atual += natalidade-mortalidade;
        anos++;
    }
    printf("Years: %d\n", anos);
}
