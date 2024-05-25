#include <stdio.h>


int main()
{  
    
    //STRUCT DENTRO DA MAIN() 
    
    
      //Definindo a struct  
      struct{

         char nome[20];
         int idade_ano;
         float saldo_bancario;
         char sexo;


      }Usuario; 

      //Declarando a struct
      struct Usuario;


      //Acessando variveis da struct
      
        Usuario.nome;
        Usuario.idade_ano;
        Usuario.saldo_bancario;
        Usuario.sexo;
    
    

    //Outras formas de definir uma struct
   
      struct Usuario{

         char nome[20];
         int idade_ano;
         float saldo_bancario;
         char sexo;
   
      };

   

      struct Usuario Pessoa;

      Pessoa.nome;
      Pessoa.idade_ano;
      Pessoa.saldo_bancario;
      Pessoa.sexo;

    
    //Definindo struct usando typedef

       typedef struct{
            
            char nome[20];
            int idade_ano;
            float saldo_bancario;
            char sexo;

       }Conta;

        Conta Banco;

        Banco.nome;
        Banco.idade_ano;
        Banco.saldo_bancario;
        Banco.sexo;
      
      //Ao usar typedef definimos que Conta é sinônimo de struct , logo não precisamos declarar a struct usando "struct Conta Banco"




      
    printf("DIGITE UM NOME :\n");

    fgets(Usuario.nome , 20 , stdin);

    printf("DIGTE  IDADE E SALDO BANCARIO:\n");
    
    scanf("%d %f" , &Usuario.idade_ano , &Usuario.saldo_bancario);

    Usuario.sexo = 'H';

    printf("NOME = %s | IDADE = %d| SALDO = %.2f | SEXO = %c\n" , Usuario.nome , Usuario.idade_ano , Usuario.saldo_bancario , Usuario.sexo);



    

}