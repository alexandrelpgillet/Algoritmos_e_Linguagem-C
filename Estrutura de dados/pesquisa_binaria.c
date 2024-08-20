#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
     int num;

}Vetor;


int pesquisa_binaria(Vetor *Lista , int numero, int inicio , int fim)
{
    
   
   int posicao = (inicio+fim)/2;


   if(numero==(Lista+posicao)->num)
   {
      return posicao;
   }
   else
   {
      if(numero>(Lista+posicao)->num)
      {
          return pesquisa_binaria(Lista,numero, inicio , posicao-1);
      }

      else 
      {
        if(numero<(Lista+posicao)->num)
        {
            return pesquisa_binaria(Lista,numero,posicao+1, fim);
        }
        else
        {
            return 0;
        }
      }
   }
    



}

int main()
{
    int i;
    int meio;
    int busca;


    Vetor *Lista_numeros;

    Lista_numeros = (Vetor*) malloc(sizeof(Vetor)*100);

    for(i=0  ; i<1000 ; i++)
    {
        Lista_numeros->num = i+1;
    }
    
    busca=878;

    meio = 999;

    //scanf("%d", &busca);

    pesquisa_binaria(Lista_numeros, busca, 0, 99);


}