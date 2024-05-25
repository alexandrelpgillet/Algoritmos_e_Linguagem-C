#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    char nome[20];
    int numero;
    char email[20]; 

    
}Agenda;


int main()
{   
  
    
    
    //Declarando ponteiro *Contato do tipo Agenda
    Agenda *Contato;
    
    //Alocando memória de forma dinâmica para Contato, o tamanho é o tamanho da struct Agenda*1000;
    Contato= malloc(sizeof(Agenda)*1000);


    if(Contato==NULL)
    {
        printf("ERRO DURANTE ALOCAÇÃO DE MEMÓRIA\n");
        return -1;
    }
    
    //Preenchendo 1000 contatos no ponteiro *Contato
    for(int i=0 ; i<1000 ; i++)
    {   

        strcpy((Contato+i)->nome , "Contato");
        (Contato+i)->numero = 1000+i;
        strcpy((Contato+i)->email , "@email.com");

        
    }


    for(int i = 0 ; i<1000 ; i++)
    {
        printf("NOME = %s | NUMERO =  %d  | EMAIL = %s\n" , (Contato+i)->nome , (Contato+i)->numero , (Contato+i)->email);
    }
    
    //Liberando espaço alocado
    free(Contato);


    /*VANTAGENS DE SE USAR ALOCAÇÂO DINÂMICA 

       1)Podemos trabalhar com problemas cujo o tamanho da struct é indefinida, como agenda(infinitos contatos);
       2)Podemos sempre que precisar realocar mais memória usando a função realloc();
       3)Caso não seja necessário podemos usar realloc() para reduzir a memória alocada;
       4)Podemos liberar a memoria quando quisermos usando a função free().

    */


}