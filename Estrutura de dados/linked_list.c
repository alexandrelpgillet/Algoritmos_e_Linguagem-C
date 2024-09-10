#include <stdlib.h>
#include <stdio.h>


typedef struct {

    int data;
    struct node *link;

}node;



void inserir(node *Lista , int i)
{

   

    if((Lista+i)->link==NULL)
    {

        scanf("%d", &(Lista+i)->data);
        
        Lista= (node*) realloc(Lista, sizeof(node)*(i+1));

        Lista->link = (Lista+i);


    }
    else
    {
        inserir(Lista , i+1);
    }

}

void imprimir(node *Lista)
{
    int i =0 ;

    while((Lista+i)->link!=NULL)
    {
        printf("VALOR ARMAZENADO NO NODE : %d | ENDEREÇO DO PROXIMO NODE: %p\n" , (Lista+i)->data , (Lista+i)->link);
    }
}



int main()
{
    
    node *Lista;

    Lista= (node*) malloc(sizeof(node));

    Lista->link = NULL;


    for(int i = 0 ; i<5 ; i++)
    {
        inserir(Lista, 0);
    }

    imprimir(Lista);





}