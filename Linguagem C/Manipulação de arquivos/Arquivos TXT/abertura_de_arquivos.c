#include <stdio.h>

int main(){



    FILE *arquivo; // variavel do tipo FILE sempre será ponteiro;

    arquivo = fopen("nome_arquivo.txt" , "w");

    //Verificando se o arquivo foi aberto
    
    if(arquivo!=NULL)
    {
      printf("ARQUIVO ABERTO COM SUCESSO\n");

    }
    else 
    {
      return -1;
    }

    /*
    
     1)Declarar um ponteiro do tipo FILE e realizar a abertura do arquivo .txt , atráves do comando :
     
        - fopen("nome_arquivo.txt", "modo de abertura do arquivo ");

     2)Modos de abertura do arquivo :

        -"w" = modo de escrita(write) , caso não exista o arquivo com o determinado nome ,  o arquivo será criado , caso já exista o arquivo já existente sera apagado e criado novamente;

        
        -"r" = modo de leitura (read) , caso não exista o arquivo com o determinado nome , a variavel arquivo retornará NULL , caso exista o arquivo será aberto para a leitura;

        
        -"a"= modo de leitura e escrita no final do arquivo (ANEXO / APPEND ), caso não exista o arquivo com o determinado nome a variavel arquivo retornará null;


        -"w+" = modo de escrita e leitura , caso não exista o arquivo com o determinado nome ,  o arquivo será criado , caso já exista o arquivo já existente sera apagado e criado novamente;

        
        -"r+" = modo de leitura e escrita ,  caso não exista o arquivo com o determinado nome ,  a variavel arquivo retornará NULL , caso já exista será aberto tanto para a leitura quanto para escrita.

        
        -"a+" = modo de leitura e escritaa no final do arquivo (ANEXO/APPEN) , caso não exista o arquivo com o determinado nome , o arquivo será criado , caso já exista o arquivo , o ponteiro de leitura/escrita do arquivo será deslocado para o final do arquivo;





    
    */

   fclose(arquivo); // Função para fechar o arquivo 







}