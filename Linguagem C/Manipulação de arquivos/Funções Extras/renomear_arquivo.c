#include <stdio.h>

int main()
{
    
    int i;
    FILE *arquivo = fopen("arquivo.txt" , "w");

    fclose(arquivo);
    

    //FUNÇÃO rename("nome do arquivo atual" , "novo nome do arquivo")
    
    /*
      rename() return 0 quando a operação renomar foi concluida com sucesso
      rename() return -1 quando a não foi possível realizar a operação de renomear o arquivo
    */
    
    //Obs:Sempre que usar essa função , o arquivo precisa estar fechado
     
    
    i = rename("arquivo.txt" , "arquivo_modiicado.txt");

    if(i==0)
    {
        printf("Arquivo renomeado com sucesso\n");
    }
    else 
    {
        printf("ERRO - Nao foi possivel renomar o arquivo\n");
    }

  

    

    


}