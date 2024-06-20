// Chamando as bibliotecas
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void){

    // Criou e armazenou a entrada do usuário
    float troco_devido = 0;
    do{
        troco_devido = get_float("Troco Devido: ");
    // verifica se o valor é válido
    }while(troco_devido < 0.00);

    // convertendo o valor para moedas e criando o contador de moedas
    int troco = round(troco_devido*100);
    int moedas = 0;

    // Repete as verificações enquanto troco ainda tem algum valor armazenado nele
    while(troco > 0){
        // Verifica se troco é maior que 25 centavos
        if(troco >=  25){
            // Se for subtrai 25 centavos de troco e soma mais um na variável moedas
            troco -= 25;
            moedas++;
        // Verifica se troco é maior que 10 centavos
        }else if(troco >= 10){
            // Se for subtrai 10 centavos de troco e soma mais um na variável moedas
            troco -= 10;
            moedas++;
        // Verifica se troco é maior que 5 centavos
        }else if(troco >= 5){
            // Se for subtrai 5 centavos de troco e soma mais um na variável moedas
            troco -= 5;
            moedas++;
        // Verifica se troco é maior que 1 centavos
        }else if(troco >= 1){
            // Se for subtrai 1 centavos de troco e soma mais um na variável moedas
            troco -= 1;
            moedas++;
        }
    }

    // Imprime o resultado.
    printf("%d\n",moedas);
}
