#include <stdio.h>
#include <stdlib.h>

typedef struct V
{
    int num;

}Vetor;


int quant_search =0;


unsigned int busca_binaria(Vetor *Lista_numeros, unsigned int  busca , unsigned int extremidade_baixa , unsigned int  extremidade_alta)
{

    printf("EXTREMIDADE BAIXA %u: EXTREMIDADE ALTA %u\n" , extremidade_baixa, extremidade_alta);

    quant_search+=1;

    unsigned int posicao = (extremidade_baixa+extremidade_alta)/2;


    if(busca==(Lista_numeros+posicao)->num)
    {
        return posicao;

    }
    else
    {

        if(extremidade_alta==extremidade_baixa)
        {

            return -1;

        }

    }



    if(busca<(Lista_numeros+posicao)->num)
    {

        return busca_binaria(Lista_numeros, busca , extremidade_baixa , posicao-1);

    }

    if(busca>(Lista_numeros+posicao)->num)
    {

        return busca_binaria(Lista_numeros, busca , posicao+1 , extremidade_alta);

    }





}



int main()
{
    unsigned int i;

    unsigned int  busca;

    unsigned int tamanho_vetor = 100000000;

    Vetor *Lista_numeros;

    Lista_numeros = (Vetor*) malloc(sizeof(Vetor)*tamanho_vetor);


    for(i=0  ; i<tamanho_vetor ; i++)
    {
        (Lista_numeros+i)->num =i;

    }



    srand(time(NULL)*time(NULL));

    busca=rand()%tamanho_vetor;




    int x = busca_binaria(Lista_numeros, busca, 0, tamanho_vetor-1);

    printf("\n\n\n\n");

    printf("O NUMERO BUSCADO E %u\n", busca);

    if(x== 0) {

        printf("Não foi encontrado o elemento no vetor\n");
    }
    else {

        printf("POSICAO DO ELEMENTO BUSCADO:%u\n", x);

    }

    printf("QUANTIDADE DE BUSCAS : %d\n" , quant_search );


}