#include <stdio.h>
#include <string.h>


int  pontuacao(char string [20])
{
    if(strcmp(string , "!") == 0 ||strcmp(string , ".") == 0 || strcmp(string , "?") == 0 || strcmp(string , ".") == 0 || strcmp(string , ",") == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}

void remove_space_breakline(char string [20])
{
    int i =0;
    
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

            default:
            
            break;
        }

        i++;

    }

    strcat(string , ".txt");
}

int main()
{
    FILE *arquivo;

    char nome_arquivo[20];
    char palavra[20];
    int quantidade_palavras = 0;

    printf("DIGITE O NOME DO ARQUIVO QUE VC DEJEJA ABRIR\n");
    
    fgets(nome_arquivo, 15 , stdin);
    
    //FUNÇÃO PARA REMOVER ESPACOS E QUEBRA DE LINHA DA STRING nome_arquivo
    remove_space_breakline(nome_arquivo);
    
    //ABRINDO ARQUIVO COM NOME nome_arquivo  NO MODO DE LEITURA
    arquivo = fopen(nome_arquivo , "r");
    

    //VERIFICANDO SE O ARQUIVO FOI ABERTO
    if(arquivo == NULL)
    {
        printf("ERROR o Arquivo %s  não encontrado\n" , nome_arquivo);
        
        return -1;
    }


    //LENDO ATÉ O FINAL DO ARQUIVO USANDO FSCANF
    while(!feof(arquivo))
    {
        fscanf(arquivo, "%s" , palavra );
        
        quantidade_palavras+=pontuacao(palavra);

    }

    printf("%d palavra(s) encontradas no arquivo\n", quantidade_palavras);

    fclose(arquivo);



    


}