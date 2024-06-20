#include <stdio.h>
#include <cs50.h>

int main (void){

    long cartao = 0;

    do
    {
        cartao = get_long("Número do cartão: ");
    }while(cartao == 0);

    int index = 0;
    long temp = cartao;

    int soma = 0, soma1 = 0, soma2 = 0;
    int contador = 0;

    while(temp != 0){

        if(contador >= 1){
            if((temp%10)*2 > 9){
                soma1+= ((temp%10)*2)%10 + ((temp%10)*2)/10;
            }else{
                soma1 += (temp%10)*2;
            }
            contador = 0;
        }else{
            soma2 += temp%10;
            contador++;
        }

        temp /= 10;
        index++;
    }

    soma = soma1 + soma2;

    int ncard[index];

    for(int i = 0; i < index; i++){
        ncard[i] = cartao%10;
        cartao = cartao / 10;
    }

    int _2digitos = ncard[index-1]*10 + ncard[index-2];
    if((_2digitos == 34 || _2digitos == 37) && soma % 10 == 0 && index == 15){
        printf("AMEX");
    }else if((_2digitos >= 51 && _2digitos <= 55) && soma % 10 == 0 && index == 16){
        printf("MASTERCARD");
    }else if(_2digitos/10 == 4 && soma % 10 == 0 && (index == 13 || index == 16)){
        printf("VISA");
    }else{
        printf("INVALID");
    }

    printf("\n");
}
