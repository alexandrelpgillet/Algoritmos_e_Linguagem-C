#include <stdio.h>

int main()
{  
    
    //STRUCT DENTRO DA MAIN()
    struct
    {

        char nome[20];
        int idade_ano;
        float saldo_bancario;
        char sexo;


    }Usuario;

    struct Usuario;

    fgets(Usuario.nome , 20 , stdin);
    
    scanf("%d %f" , &Usuario.idade_ano , &Usuario.saldo_bancario);

    Usuario.sexo = 'H';

    printf("NOME = %s | IDADE = %d| SALDO = %.2f | SEXO = %c\n" , Usuario.nome , Usuario.idade_ano , Usuario.saldo_bancario , Usuario.sexo);



    

}