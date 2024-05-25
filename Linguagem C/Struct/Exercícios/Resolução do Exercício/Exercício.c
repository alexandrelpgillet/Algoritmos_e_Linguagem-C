#include <stdio.h>
#include <stdlib.h>



int quantidade_usuarios=0;

typedef struct{

    char nome[20];
    int numero_conta;
    float saldo;

}Banco;



void flush_in()
{
    int ch;

    do{

      ch = fgetc(stdin);

    }while (ch!='\n' && ch!='\n');
    
    
}




void criar_conta(Banco *Conta)
{  

    printf("Digite o nome do usuario:\n");

    fgets((Conta+quantidade_usuarios)->nome , 20 , stdin);

    printf("Digite o numero da conta:\n");

    scanf("%d" , &(Conta+quantidade_usuarios)->numero_conta);

    printf("Digite o saldo da conta:\n");

    scanf("%f" , &(Conta+quantidade_usuarios)->saldo);




    while((Conta+quantidade_usuarios)->saldo<0)
    {
        printf("ERRO - SALDO NEGATIVO INVALIDO\n");
        scanf("%f" , &(Conta+quantidade_usuarios)->saldo);

    }


    quantidade_usuarios++;

}


int depositar(Banco *Conta)
{   

    int ID;
    float valor_depositado;
    
    
    if(quantidade_usuarios==0)
    {
        printf("NENHUMA CONTA CADASTRADA , PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
        
        getchar();
        
        return -1;
    }
    else
    {  


        for(int i = 0 ; i<quantidade_usuarios ; i++)
        {
            
            printf("ID)%d | NOME = %s | NUMERO DA CONTA = %d| SALDO = R$ %.2f\n" , i , (Conta+i)->nome , (Conta+i)->numero_conta , (Conta+i)->saldo);

        }

        printf("DIGITE O ID DA CONTA QUE DESEJA FAZER O DEPOSITO\n");
        
        scanf("%d" , &ID);

        while(ID<0 || ID>quantidade_usuarios-1)
        {
            printf("ERROR - ID INVALIDO , DIGITE VALORES ENTRE 0 - %d" ,quantidade_usuarios-1);
            
            scanf("%d", &ID);
        }

        system("cls");

        printf("DIGITE O VALOR A SER DEPOSITADO\n");
        
        scanf("%f" , &valor_depositado);

        while(valor_depositado<0)
        {
            printf("ERROR - VALOR NEGATIVOS PARA DEPOSITO NAO SAO ACEITOS\n");
            
            scanf("%f" , &valor_depositado);
        }


        (Conta+ID)->saldo+=valor_depositado;
        
        flush_in();

        printf("DEPOSITO REALIZADO COM SUCESSO, PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
        
        getchar();

        return 0;

        





    }
    

}

int sacar(Banco *Conta)
{
    
    int ID;
    float valor_saque;

    
    if(quantidade_usuarios==0)
    {
        printf("NENHUMA CONTA CADASTRADA , PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
        
        getchar();
        
        return -1;


    }
    else 
    {   

        for(int i = 0 ; i<quantidade_usuarios ; i++)
        {
            
            printf("ID)%d | NOME = %s | NUMERO DA CONTA = %d | SALDO = R$ %.2f\n" , i , (Conta+i)->nome , (Conta+i)->numero_conta , (Conta+i)->saldo);

        }

        printf("DIGITE O ID DA CONTA PARA SAQUE\n");
        
        scanf("%d" , &ID);



        while(ID<0 || ID>quantidade_usuarios-1)
        {
            printf("ID INVALIDO , DIGITE VALORES ENTRE 0 - %d\n" , quantidade_usuarios-1);
            
            scanf("%d" , &ID);
        }

        
        
        printf("DIGITE O VALOR A SER SACADO\n");
        
        scanf("%f", &valor_saque);

        
        
        while(valor_saque<0 || valor_saque>(Conta+ID)->saldo)
        {
            printf("ERRO VALOR INVALIDO , NAO ACEITAMOS VALOR NEGATIVO PARA SAQUE O VALORES ACIMA DO SALDO DA CONTA\n");
            
            scanf("%f" , &valor_saque);
        }

        
        (Conta+ID)->saldo-=valor_saque;
        
        flush_in();
        
        printf("SAQUE REALIZADO COM SUCESSO , PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
        
        getchar();

        return 0;






    }
}

int imprimir_contas(Banco *Conta)
{
    if(quantidade_usuarios==0)
    {
        printf("NENHUMA CONTA CADASTRADA , PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
        
        getchar();
        
        return -1;

    }
    else
    {

        for(int i= 0 ; i<quantidade_usuarios ; i++)
        {
            printf("NUMERO DA CONTA = %d | SALDO DA CONTA =  R$ %.2f\n" , (Conta+i)->numero_conta , (Conta+i)->saldo);
        }

        printf("\n\n");
        
        printf("PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU\n");
        
        getchar();
        
        return 0;




    }
}






int main()
{  
    
    int flag_menu=1;
    int resposta_menu;
    
    Banco *Conta;

    Conta = malloc(sizeof(Banco)*500);

    if(Conta == NULL)
    {
        
        printf("ERRO NA ALOCAÇÃO DE MEMORIA\n");
        
        return -1;

    }


    while(flag_menu)
    {


        
        system("cls");

        printf("--------MENU DE BANCARIO--------\n");
        printf("|                               |\n");
        printf("|1)Criar conta                  |\n");
        printf("|2)Depositar valor              |\n");
        printf("|3)Sacar valor                  |\n");
        printf("|4)Imprimir saldo               |\n");
        printf("|5)Sair do MENU                 |\n");
        printf("|-------------------------------|\n");

        printf("DIGITE O MENU QUE DESEJA ACESSAR (1 - 5)\n");
        scanf("%d" , &resposta_menu);


        flush_in();

        

       switch(resposta_menu)
       {

           case 1:

             system("cls");
             criar_conta(Conta);

           break;

           case 2:

             system("cls");
             depositar(Conta);
            
           break;


           case 3 :

              system("cls");
              sacar(Conta);

           break;

           case 4 :

              system("cls");
              imprimir_contas(Conta);
           
           break;

           case 5:
              system("CLS");
              printf("Programa Encerrado !!!\n");
              flag_menu=0;

           break;

           default:
           printf("ERROR , RESPOSTA INVALIDA , PRESSIONE QUALQUER TECLA\n");
           getchar();
           system("cls");
           
           



       }

    }

return 0;
     



    

}