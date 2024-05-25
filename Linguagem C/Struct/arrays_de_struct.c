#include <stdio.h>

struct Pessoa {
    
    char nome[20];
    int idade;
    float altura;
    char sexo;
  
};




int main()
{
    
    //Declarando o array Lista[5] do tipo struct Pessoa
    struct Pessoa Lista[5] =  {
        
        {"Joao Silva" , 25 , 1.75 , 'H'},

        {"Maria Oliveira" , 34 , 1.60 , 'M'},

        {"Pedro Souza" , 28 , 1.82  , 'H'}, 

        {"Ana Costa" , 42 , 1.68 , 'M'}, 

        {"Lucas Fernandes" , 19 , 1.90 , 'H'}
        
    
    };
    

    for(int i = 0 ; i<5 ; i++)
    {
       printf("NOME = %s  | IDADE = %d | ALTURA = %.2f | SEXO = %c\n" , Lista[i].nome , Lista[i].idade , Lista[i].altura , Lista[i].sexo);
    
    }

    
    
    
}