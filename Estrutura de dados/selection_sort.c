#include <stdio.h>



void selection_sort(int *V , int N){
    
    int aux;
    int pos;
    int num;

    for(int i =0 ; i<N-1 ; i++)
    {    

        num= V[i];
        

        pos = i;

        for(int j = i+1 ; j<N ; j++)
        {

            if(num>V[j])
            {
                pos = j;
                num= V[j];
            }

        }

        aux = V[i];

        V[i]=num;
        V[pos] = aux;

    }


}


int main()
{

    int V[10] = {99 , 1, -12, 121, 14, 888, 17 , 51 , 67 , 100};

    selection_sort(V , 10);

    for(int i =0 ; i<10 ; i++)
    {
        printf("%d " , V[i]);
    }

}