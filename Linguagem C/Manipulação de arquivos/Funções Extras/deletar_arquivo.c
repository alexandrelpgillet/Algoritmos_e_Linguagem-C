#include <stdio.h>

int main()
{  

    //FUNÇÃO remove("nome do arquivo")
      
      //remove() return -1 caso não encontre o arquivo a ser excluido
      //remove() return 0 caso seja escontrado o arquivo e ele seja excluido
     
    
    int i= remove("arquivo.txt");


    if(i==0)
    {
        printf("O arquivo foi excluido com SUCESSO!\n");
    }
    else
    {
        printf("ERRO - O arquivo nao foi encontrado para ser excluido\n");
    }




   
}