#include <stdio.h>

int main(){

    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "w+");



    char nome[]="Estudante";
    int idade = 20 ;
    char sexo ='M';



    //FUNÇÕES PARA ENTRADA DE DADOS EM UM ARQUIVO TXT

    fprintf(arquivo , "%s %d %c \n" , nome , idade , sexo); 
    fputs(nome , arquivo);
    fputc(sexo , arquivo);

    /*
    
    fprintf()= Usado para escrever variaveis do tipo INT ,LONG INT , CHAR , STRING 
    fputs() = Usado para strings
    fputc() = Usado para char
    
    
    */

   //FUNÇÕES PARA LEITURA DE DADOS DE UM ARQUIVO TXT
   
   char leitura_nome[11];
   int leitura_idade;
   char leitura_sexo;
   char conteudo_arquivo[100];
   char caracter;

   
   rewind(arquivo);//Função para retornar o ponteiro de leitura e escrita do arquivo para o inicio do arquivo

   fscanf(arquivo , "%s %d %c" ,  leitura_nome , &leitura_idade , &leitura_sexo); 

   rewind(arquivo);//Função para retornar o ponteiro de leitura e escrita do arquivo para o inicio do arquivo

   fgets(conteudo_arquivo , 100 , arquivo);

   rewind(arquivo);//Função para retornar o ponteiro de leitura e escrita do arquivo para o inicio do arquivo

   caracter = fgetc(arquivo);

   /*

   fscanf() = Leitura de variaveis do tipo INT , LONG, CHAR , STRING
   fgets()= Ler todo o conteudo do arquivo até encontrar '\n' e armazenar um STRING
   fegct()=Ler um caracter contido no arquivo
   
   

   */

    fclose(arquivo);



    printf("%s\n" , leitura_nome);
    printf("%d\n" , leitura_idade);
    printf("%c\n" , leitura_sexo);
    printf("%s" , conteudo_arquivo);
    printf("%c\n" , caracter);



    



}