#include <stdio.h>



int binary_search(int *V , int X ,int begginng , int end ){
     
     if(begginng>=end)
     {

        if(V[begginng]==X)
        {
           return begginng;
        }
        else 
        {
            return -1;
        }

     }
     else
     {

        int middle;

        middle = (begginng+end)/2;

        if(X>V[middle])
        {

            binary_search(V , X,middle+1 , end);

        }
        else
        {

            binary_search(V , X ,  begginng , middle);


        }


     }



}


int main()
{

    int V[10] = {1,2,3,4,5,6,7,8,9,10};

    
    int pos;

    pos= binary_search(V , 5 , 0 , 9);

    printf("Posicao do elemento : %d", pos);






}