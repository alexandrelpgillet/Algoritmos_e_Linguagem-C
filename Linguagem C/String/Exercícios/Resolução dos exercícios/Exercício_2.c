#include <stdio.h>


void strcopy(char string_destiny[20] , char string_origin[20])
{

    int i=0;
    
    while(string_origin[i]!='\0')
    {
        string_destiny[i]=string_origin[i];
        
        i++;
    }

    string_destiny[i]='\0';

}



int main()
{
    
    char string[20];
    char string_aux[20];

    fgets(string, 20 , stdin);
    strcopy(string_aux , string);

    printf("%s" , string_aux);


}