#include <stdio.h>
#include <string.h>

void right(char string[20] , int n)
{

    int TAM = strlen(string)-1;

    
    for(int i = TAM-n ; i<TAM ; i++)
    {
        printf("%c" , string[i]);
    }

    printf("\n");

}

void left(char string[20] , int n)
{  

    

    for(int i= 0 ; i<n ; i++)
    {
        printf("%c" , string[i]);
    }
    
    printf("\n");



}

int main()
{

    char string[20];
    fgets(string , 20 , stdin);
    
    right(string, 5) ;
    left(string, 3);


}