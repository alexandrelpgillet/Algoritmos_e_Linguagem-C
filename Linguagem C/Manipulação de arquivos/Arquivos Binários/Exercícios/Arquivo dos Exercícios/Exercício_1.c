#include <stdio.h>
#include <stdlib.h>
#include <string.h>





typedef struct 
{
    int id;
    char nome[20];
    int quantidade;
    float preco;

}Produto;




int main()
{  
    
    FILE *arquivo_txt;
    FILE *arquivo_binario;
    Produto *Lista;
    Produto Aux;
    int i =0 ;
    int i2;

    int id_aux;
    char nome_aux[20];
    int quantidade_aux;
    float preco_aux;




    arquivo_txt = fopen("produtos.txt" , "w+");

    Lista = malloc(sizeof(Produto)*10000);

    while(scanf("%d %[^\n] %d %f" , &id_aux , nome_aux , &quantidade_aux , &preco_aux)!=EOF)
    {
        
        strcat(nome_aux , "&");
        fprintf(arquivo_txt , "%d %s %d %f\n" , id_aux , nome_aux , quantidade_aux , preco_aux );
        
    }




    rewind(arquivo_txt);

    while(!feof(arquivo_txt))
    {   
        i2 = 0;

        fscanf(arquivo_txt , "%d" , &(Lista+i)->id);

        fscanf(arquivo_txt , "%c" , &(Lista+i)->nome[i2]);

        
        while((Lista+i)->nome[i2]!= '&')
        {   
            i2++;
            fscanf(arquivo_txt , "%c" , &(Lista+i)->nome[i2]);
            
            
        }

        (Lista+i)->nome[i2] = '\0';

    
        
        fscanf(arquivo_txt , "%d %f" , &(Lista+i)->quantidade , &(Lista+i)->preco);
        
        i++;

    }


    i--;
    fclose(arquivo_txt);


    arquivo_binario = fopen("produtos.bin" , "w+b");
    
    
    for(i=i ; i>0 ; i--)
    {   
    
        fwrite((Lista+i-1) , sizeof(Produto), 1 , arquivo_binario);
    }

    rewind(arquivo_binario);

    

    while(fread(&Aux , sizeof(Produto) , 1, arquivo_binario))
    {
        

        printf("ID DO PRODUTO : %d | NOME PRODUTO %s | QUANTIDADE DO PRODUTO = %d| PRECO = %.2f \n " , Aux.id , Aux.nome , Aux.quantidade , Aux.preco);
    }

    fclose(arquivo_binario);
   

    
    

    


}