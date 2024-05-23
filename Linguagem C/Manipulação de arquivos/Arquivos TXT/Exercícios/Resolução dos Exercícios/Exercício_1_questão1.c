#include <stdio.h>
#include <string.h>


void remove_spaces_breakline(char string[20])
{
    int i = 0;

    while(string[i]!='\0')
    {
        
        switch(string[i])
        {
            case ' ':

              string[i]='_';
            
            break;

            case '\n':
              
              string[i]='\0';
            
            break;

            default :
            
            break;  
        }

        i++;
    }

    strcat(string, ".txt");



}


int main()
{   

    FILE *arquivo_1;
    FILE *arquivo_2;
    FILE *arquivo_3;

    char nome_arquivo_1[20];
    char nome_arquivo_2[20];

    char conteudo_arquivo_1[120];
    char conteudo_arquivo_2[120];
    char conteudo_arquivo_3[120];


    //NOME DOS ARQUIVOS 1 E 2
    printf("DIGITE O NOME DO ARQUIVO 1:\n");
    fgets(nome_arquivo_1 , 15 , stdin );

    
    printf("DIGITE O NOME DO ARQUIVO 2\n");
    fgets(nome_arquivo_2 , 15,  stdin);

    //FUNÇÃO PARA REMOVER ESPACOS NA STRING E CONCATENANDO COM A STRING ".txt"
    remove_spaces_breakline(nome_arquivo_1);
    remove_spaces_breakline(nome_arquivo_2);

    
    //ENTRADA DO CONTEUDO DOS ARQUIVOS 1 E 2
    printf("DIGITE O CONTEUDO DO ARQUIVO 1:\n");
    fgets(conteudo_arquivo_1, 100 , stdin);

    
    printf("DIGITE O CONTEUDO DO ARQUIVO 2:\n");
    fgets(conteudo_arquivo_2,100 , stdin);


    //ABRINDO OS ARQUIVOS 1 E 2 COM OS RESPECTIVOS NOMES ESCOLHIDOS E ABRINDO O ARQUIVO 3 
    arquivo_1 = fopen(nome_arquivo_1 , "w+");
    arquivo_2 = fopen(nome_arquivo_2 , "w+");
    arquivo_3 = fopen("arquivo_3.txt" , "w");

    //ESCREVENDO O CONTEUDO RESPECTIVO DO ARQUIVO 1 E 2
    fprintf(arquivo_1 , "CONTEUDO ARQUIVO 1 : %s" , conteudo_arquivo_1);
    fprintf(arquivo_2 , "CONTEUDO ARQUIVO 2 : %s" , conteudo_arquivo_2);

    //MOVENDO O PONTEIRO DE LEITURA/ESCRITA DOS ARQUIVOS 1 E 2 PARA O INICIO DO ARQUIVO
    rewind(arquivo_1);
    rewind(arquivo_2);

    
    //LENDO O CONTEUDO DO ARQUIVO 1 E SALVANDO DA NA VARIAVEL CONTEUDO_ARQUIVO_3
    fgets(conteudo_arquivo_3 , 120 , arquivo_1);

    //ESCREVENDO A STRING CONTEUDO_ARQUIVO_3 NO ARQUIVO 3
    fprintf(arquivo_3 , "%s" , conteudo_arquivo_3);
    
    //LENDO O CONTEUDO DO ARQUIVO 2 E SALVANDO DA NA VARIAVEL CONTEUDO_ARQUIVO_3
    fgets(conteudo_arquivo_3 , 120 , arquivo_2);

    //ESCREVENDO A STRING CONTEUDO_ARQUIVO_3 NO ARQUIVO 3
    fprintf(arquivo_3 , "%s" , conteudo_arquivo_3);

    
    
    //FECHANDO TODOS OS ARQUIVOS ABERTOS PELA FUNÇÂO fopen()
    fclose(arquivo_1);
    fclose(arquivo_2);
    fclose(arquivo_3);


    







}

