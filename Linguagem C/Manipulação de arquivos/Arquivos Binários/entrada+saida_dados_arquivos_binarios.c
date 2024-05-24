#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nome[20];
    int idade;
    float saldo;
}Conta;

typedef struct
{
   char nome[20];
   int idade;
   long int numero;

}Contato;


void flush_in()
{
  int ch;

  do
  {

    ch=fgetc(stdin);

  }while(ch!='\n' && ch!='\0');
  
}







int main()
{

    FILE *arquivo_binario ;


    
    
  
      //-1)Variavel do tipo int , float , long int , char 
      
      arquivo_binario = fopen("arquivo.bin" , "w+b");

      int num=10;
      float num_float = 119.99;
      long int num_long = 100000000;
      char caracter= 'a';


      int num_aux;
      float num_float_aux;
      long int num_long_aux;
      char caracter_aux;
      
      //ESCREVENDO AS VARIAVEIS num , num_float ,num_long , caracter NO ARQUIVO BINARIO
      fwrite(&num , sizeof(int) , 1 , arquivo_binario);           
      fwrite(&num_float , sizeof(float), 1 , arquivo_binario);
      fwrite(&num_long , sizeof(long int) , 1 , arquivo_binario);
      fwrite(&caracter , sizeof(char) , 1 , arquivo_binario);    

      rewind(arquivo_binario);
      
      //LENDO O ARQUIVO BINARIO E SALVANDOS OS VALORES ENCONTRADOS NAS VARIAVEIS num_aux, num_float_aux , num_long_aux , caracter_aux
      fread(&num_aux , sizeof(int) ,1 , arquivo_binario);
      fread(&num_float_aux , sizeof(float) , 1 , arquivo_binario);
      fread(&num_long_aux , sizeof(long int) , 1 , arquivo_binario);
      fread(&caracter_aux , sizeof(char) , 1 , arquivo_binario);


      printf("INT = %d | FLOAT = %f | LONG INT =%ld | CHAR = %c\n", num_aux , num_float_aux , num_long_aux , caracter_aux);


     fclose(arquivo_binario);


    
     



      //-2)Vetores de char e strings

      arquivo_binario = fopen("arquivo.bin" , "w+b");
      
      char string[100];
      
      char string_2[100];


      printf("DIGITE UM STRING\n");
      fgets(string , 100 , stdin);
      
      //ESCREVENDO A VARIAVEL string NO ARQUIVO BINARIO
      fwrite(string , sizeof(string) , 1 , arquivo_binario );

      rewind(arquivo_binario);

      //LENDO O ARQUIVO BINARIO E SALVANDO NA VARIAVEL string_2
      fread(string_2 , sizeof(string) , 1 , arquivo_binario);


      printf("STRING = %s" , string_2);


      fclose(arquivo_binario);


     




    
      //-3)Vetores de int , float

      arquivo_binario = fopen("arquivo.bin" , "w+b");

      int lista_num[10]={1,2,3,4,5,6,7,8,9,10};

      float lista_num_float[10]={0.1 , 0.2 , 0.3 , 0.4 , 0.5 , 0.6 , 0.7 , 0.8 , 0.9 , 1.0};


      int lista_num_aux[10];
      float lista_num_float_aux[10]; 
      
      //ESCREVENDO OS VETORES lista_num , lista_num_float  NO ARQUIVO BINARIO
      fwrite(lista_num , sizeof(lista_num) , 1 , arquivo_binario);
      fwrite(lista_num_float , sizeof(lista_num_float) , 1 , arquivo_binario);


      rewind(arquivo_binario);
      
      //LENDO OS VETORES DO ARQUIVO BINARIO E ARMAZENAMENTO NOS VETORES lista_num_aux , lista_num_float_aux
      fread(lista_num_aux , sizeof(lista_num) , 1 , arquivo_binario);
      fread(lista_num_float_aux , sizeof(lista_num_float) , 1 , arquivo_binario);

      
      
      
      
      for(int i=0 ; i<10 ; i++)
      {
        printf("lista_num_aux[%d] = %d |" , i , lista_num_aux[i]);

      }

      printf("\n\n");

      for(int i= 0 ; i<10 ; i++)
      {
        printf("lista_num_float_aux[%d] = %f |" , i , lista_num_float_aux[i]);
      }

      printf("\n");






    fclose(arquivo_binario);
  









   //4)LEITURA E ESCRITA DE REGISTROS(Variaveis heterogêneas primitivas)
  
  
      fopen("arquivo.bin" , "w+b");

      Conta Pessoa;
      Conta Pessoa_aux;

  
      printf("DIGITE UM NOME :\n");
      fgets(Pessoa.nome , 20 , stdin);

      printf("DIGITE IDADE E SALDO\n");

      scanf("%d %f" ,&Pessoa.idade , &Pessoa.saldo );


      //ESCREVENDO NO ARQUIVO BINARIO
      fwrite(&Pessoa , sizeof(Conta), 1 , arquivo_binario);
    
      rewind(arquivo_binario);
    
      //LENDO NO ARQUIVO BINARIO
      fread(&Pessoa_aux , sizeof(Conta) , 1 , arquivo_binario);

      printf("NOME = %s | IDADE = %d | SALDO = %.2f\n" , Pessoa_aux.nome , Pessoa_aux.idade , Pessoa_aux.saldo);

      fclose(arquivo_binario);







  //5)LEITURA E ESCRITA DE REGISTROS DO TIPO PONTEIRO
    
     fopen("arquivo.bin" , "w+b");
    
     Contato *Agenda;
     Contato *Agenda_aux;
   
     //REALIZANDO ALOCAÇÂO DINAMICA COM TAMANHO "Contato"
     Agenda = malloc(sizeof(Contato)); 
     Agenda_aux = malloc(sizeof(Contato));
    
     //ESCREVENDO O REGISTRO DO TIPO Contato *Agenda NO ARQUIVO BINARIO
     for(int i= 0 ; i<3 ; i++)
     {
      
       flush_in();

       printf("DIGITE UM NOME PARA O CONTATO:\n");
       fgets((Agenda+i)->nome , 20 , stdin);
       
       printf("DIGITE A IDADE DO CONTATO:\n");
       scanf("%d" , &(Agenda+i)->idade);
       
       printf("DIGITE O NUMERO DE TELEFONE DO CONTATO:\n");
       scanf("%ld" , &(Agenda+i)->numero);


      fwrite((Agenda+i) , sizeof(Contato) , 1 , arquivo_binario);


    }


    rewind(arquivo_binario);


    //LENDO O ARQUIVO BINARIO E SALVANDO OS REGISTRO ENCONTRADO NO REGSTIRO do tipo Contato *Agenda_aux
    for(int i = 0 ; i<3 ; i++)
    {
        fread((Agenda_aux+i) , sizeof(Contato), 1 , arquivo_binario);
      
    }


    for(int i =0 ; i<3  ; i++)
    {
        printf("NOME DO CONTATO : %s | IDADE CONTATO : %d | NUMERO DE TELEFONE DO CONTATO : %ld \n" ,  (Agenda_aux+i)->nome , (Agenda_aux+i)->idade , (Agenda_aux+i)->numero);
    }




    fclose(arquivo_binario);


}