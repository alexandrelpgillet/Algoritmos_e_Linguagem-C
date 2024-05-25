#include <stdio.h>
#include <string.h>


void swap(char string[20])
{
    
    int i;
    int TAM = strlen(string) - 1;
    char string_aux[20];
    
    strcpy(string_aux , string);



    for( i = 0 ; i<=TAM ; i++)
    {
        string[i]=string_aux[TAM-i];
    }

    string[i]='\0';


  
}


int main()
{

    char string[20];

    fgets(string , 20 , stdin);

    swap(string);

    printf("%s" , string);

    


}