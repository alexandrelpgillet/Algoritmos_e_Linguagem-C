#include <stdio.h>
#include <string.h>


void remove_space(char string[20])
{
    int i=0;
    int i2;
    int TAM = strlen(string);

    while(string[i]!='\0')
    {
        if(string[i]==' ')
        { 
            i2=i;

            for(i2 ; i2<=TAM+1 ; i2++)
            {
              
              string[i2]=string[i2+1];
            
            }

        }

        i++;
    }
}


int main()
{
    char string[20];

    fgets(string , 20 , stdin);
    
    remove_space(string);
    
    printf("%s" , string);
      
}