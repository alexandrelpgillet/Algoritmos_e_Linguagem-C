#include <stdio.h>

int main(){

    char nome[20];
    int quantidade;
    float valor;
    float valor_total=0;
    int quantidade_total=0;

    FILE *arquivo;
    
    
    arquivo = fopen("lista.txt" , "r");

    
    //VERIFICANDO SE FOI POSSIVEL ABRIR O ARQUIVO lista.txt
    if(arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo lista.txt\n");
        
        return -1;
    }
    
    //LENDO O ARQUIVO ATÉ O FINAL DELE
    while(!feof(arquivo))
    {
        
        fscanf(arquivo , "%s %d %f" , nome , &quantidade , &valor);

        valor_total+=valor*quantidade;
        
        quantidade_total+=1;

    }

    printf("TOTAL DE ITENS DA LISTA : %d | VALOR TOTAL DA LISTA = R$ %.2f" , quantidade_total , valor_total);

    
}