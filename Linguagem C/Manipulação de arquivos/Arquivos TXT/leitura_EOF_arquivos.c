#include <stdio.h>

int main()
{
    FILE *arquivo;
    
    arquivo = fopen("arquivo.txt" , "w+");

    
    int ano = 2024;
    int mes = 5;
    int dia =22;
    int aux;



    fprintf(arquivo , "%d %d %d" , ano , mes , dia);

    
    rewind(arquivo);

    
    
    //LEITURA ATÉ O FINAL DO ARQUIVO 

    while(fscanf(arquivo , "%d" , &aux)!=EOF)
    {
        printf("%d\n" , aux);

    }


    
    rewind(arquivo);

    

    printf("\n\n");

    
    while(!feof(arquivo))
    {
       
       fscanf( arquivo, "%d" ,&aux);
       
       printf("%d\n" , aux);

    }

   
    /*
    OBSERVAÇÃO IMPORTANTE 
    
    -O uso da função !feof() NÃO É RECOMENDADA , uma vez que ela só retorna que o arquivo chegou EOF após ter ocorrido uma tentativa de leitura , dessa forma se ocorrer algum erro na leitura , a função feof pode retornar que o arquivo não chegou em EOF , sendo que ele chegou,

    - O uso de funções de leitura()!=EOF é o mais recomendado uma vez que o teste é realizado durante a tentiva durante a leitura ,  evitnado assim leituras extras  ou loops infinitos por comportamentos inesperados do !feof() durante a leitura

    */

   
   fclose(arquivo);





    



}