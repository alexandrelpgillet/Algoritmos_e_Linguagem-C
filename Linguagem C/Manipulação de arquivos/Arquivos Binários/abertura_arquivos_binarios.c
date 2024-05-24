#include <stdio.h>

int main()
{

    FILE *arquivo_binario;

    //ARQUIVOS BINARIOS POSSUEMA A ESTENSÃO "".bin"

    arquivo_binario = fopen("arquivo.bin" , "wb");
    
    /*MODOS DE ABERTURA DE ARQUIVOS BINÁRIOS
    
    "rb" = abertura do arquivo no modo leitura , caso  o arquivo não exista a variavel que recebe a função fopen() retornará NULL;

    "wb" = abetura do arquivo no modo escrita , caso já exista um arquivo o conteúdo anterior a abertura será apagado;
    
    "ab" = abertura do arquivo para a escrita no final dele, caso não exista o arquivo , ele será criado;
    
    "r+b" = abertura no modo leitura e escrita , caso não exista o arquivo , a variavel que recebe a função fopen() retornará NULL ; 
    
    "w+b" = abertura no modo escrita e leitura , caso já exista o arquivo o conteúdo anterior a abertura será apagado; 
    
    "a+b" = abertura do arquivo para a escrita e leitura no final dele , caso não exista o arquivo , ele será criado.
    
    
    */

    fclose(arquivo_binario);
}