#include <stdio.h>
#include <string.h>


/*
    
    Vetor de char != String 

   
    -Char Array

    ['A']['B']['C']['D']['E']['F']['G']['H']['I']


    -String (Vetor de char com o caracter '\0' no final do array)

    ['A']['B']['C']['D']['E']['F']['G']['H']['I']['\0']
    
    
    */

   /*
   
   -FORMAS DE LER UMA STRING

   1)Usando getchar()
   2)Usando scanf()
   3)Usando fgets()
   4)Usando Fgetc()

   **OBS: JAMAIS USE gets() , essa função não limita o tamanho do array , podendo fazendo estourar o buffer de memória do array , tornando a função pouco segura


   -FORMAS DE IMPRIMIR UMA STRING
   
   1)Usando printf("%s" , string);
   2)Usando  printf("%c" , string[i]);



   -BIBLIOTECA <string.h>
    
     string_funções(string1 , string2)

     strcat("Ola " , "Mundo !") = concatena a string2 na string1 = " Ola Mundo !";

     strncat("Ola , "Mundo !" , 3) = contatena X caracteres da string2 para a string 1 = "Ola Mun";

     strcpy(string1 , "Ola Mundo") = copia a string2 para a string 1 = string1 = "Ola Mundo";

     strncpy(string 1 , "Ola Mundo" , 3) = copia X caracteres da string 2 para a string1 = "Ola";

     strcmp("Abacate", "Bola") = retorna um valor int de acordo com a comparação de cada caracter das duas string's pela tabela ASCII , caso string1>string2 a função retorna >1 , caso string1<string2 função retorna<1 , casos string1==string2 , a função retorna 0;

   
     strcoll("Abacate" , "Bola") = realiza a comparação de caracter a caracter das duas string , porém ao inves de usar a tabela ASCII como padrão de comparação , usa-se ordem de collation;

     strlen("Aba\n\0") = retorna o tamanho da string , não considerando o '\0' , no caso exemplo o valor retornado pela função seria 4 ('\n' conta);

    

   */

void flush_in()
{
    int ch;

    do
    {
       
       ch = fgetc(stdin);

    }while(ch!='\n' && ch!='\0');
}

int main()
{

    int i =0;
    char string1[20];
    char string2[20];
    char string3[20];

    //LENDO UM STRING USANDO fgets()

    fgets(string1 , 20 ,stdin);

    
    
    //LENDO UM STRING USANDO scanf()

    scanf("%s" , string2);

    
    
    
    //LENDO UMA STRING USAR fgetc()

    flush_in();

    string3[i]=fgetc(stdin);
    
    while(string3[i]!='\n')
    {
        i++;
        string3[i]=fgetc(stdin);
    }

    string3[i]='\0';

    
    
    
    
    
    
    //IMPRIMINDO UM STRING USANDO printf("%s" , string)
    
    printf("%s" , string1);
    printf("%s\n" , string2);
    printf("%s\n" , string3);




    //IMRPIMINDO UMA STRING USANDO printf("%c" , string[1])

    i=0;
    
    while(string1[i]!='\0')
    {

        printf("%c" , string1[i]);
        i++;

    }

    printf("\n");


    //FUNÇÕES DA BIBLIOTECA STRING.H

    char str[]="Ola";
    char str2[]="Mundo";


        //Concatenando um string
        strcat(str , " Usuario");
        printf("%s\n" , str);

    
        //Concatenando uma determinada quantidade de caracterres da string origem
        strncat(str2 , " Earth" , 2);
        printf("%s\n" , str2);

    

        //Copiando um string para outra (Sempre ficar atento ao tamnho do array da string de destino, visto que copiar uma string maior que o suportado pelo array de destino gera overflow)
        strcpy(str , "ola");
        printf("%s\n" , str);
    
    
        //Copiando uma determinada quantidade de caracteres da  string para outra 
        strncpy(str , "ABCDEFGHIJK" , 3);
        printf("%s\n" , str);

        
        //Comparando string de acordo com tabela ASCII 
        int aux = strcmp("Abacate" , "Flecha"); // |  == 0 (strings identicas ) |   >0 (string1 > string 2) | <0(string1<string2)
        printf("%d", aux);

        
        //Verificando o tamanho de uma string
        int tamanho  = strlen(str2);
        printf("%d" , tamanho);





    



}