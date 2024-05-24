#include <stdio.h>




int main()
{

    FILE *arquivo_binario = fopen("arquivo.bin" , "w+b");
    int i;
    int aux;

    for(i=0; i<1000 ; i++)
    {

        fwrite(&i , sizeof(int) , 1 , arquivo_binario);

    }

    /*FUNÇÃO FSEEK()

      SEEK_SET=DESLOCAMENTO DO PONTEIRO DE LEITURA E ESCRITA DO ARQUIVO EM RELAÇÃO AO INICIO DO ARQUIVO;
      
      SEEK_CUR=DESLOCAMENTO DO PONTEIRO DE LEITURA E ESCRITA DO ARQUIVO EM RELAÇÃO A POSIÇÃO ATUAL DO PONTEIRO;

      SEEK_END=DESLOCAMENTO DO PONTEIRO DE LEITURA E ESCRITA DO ARQUIVO EM RELAÇÃO AO FINAL DO ARQUIVO.
      

    */
   
   //DESLOCANDO  40 bytes O PONTEIRO DE LEITURA E ESCRITA EM RELAÇÂO AO INICIO DO ARQUIVO 
   fseek(arquivo_binario, 10 * sizeof(int) , SEEK_SET);
   fread(&aux, sizeof(int) , 1 , arquivo_binario);
   printf("%d\n" , aux);


   //DESLOCANDO  20 bytes a ESQUERDA ,   O PONTEIRO DE LEITURA E ESCRITA EM RELAÇÂO A POSIÇÂO ATUAL DO PONTEIRO
   fseek(arquivo_binario , -5 * sizeof(int) , SEEK_CUR);
   fread(&aux , sizeof(int), 1 , arquivo_binario);
   printf("%d\n" , aux);
   
   //DESLOCANDO 200 bytes a DIREITA , O PONTEIRO DE LEITURA E ESCRITA EM RELAÇÃO A POSIÇÃO ATUAL DO PONTEIRO
   fseek(arquivo_binario , 50 * sizeof(int) , SEEK_CUR);
   fread(&aux , sizeof(int), 1 , arquivo_binario);
   printf("%d\n" , aux);


   //DESLOCANDO 8 bytes O PONTEIRO DE LEITURA E ESCRITA EM RELAÇÃO AO FINAL DO ARQUIVO
   fseek(arquivo_binario , -2* sizeof(int) , SEEK_END);
   fread(&aux , sizeof(int), 1 , arquivo_binario);
   printf("%d\n" , aux);

   
   //DESLOCA O PONTEIRO DE LEITURA E ESCRITA PARA O INICIO DO ARQUIVO
   rewind(arquivo_binario);


   fclose(arquivo_binario);



  
    


}