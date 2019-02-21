#include <stdio.h>
#include <string.h>
#define TAM_CADENA 200

int main(int argc, char const *argv[])
{
    char *p1, *p2;
    char cadena[TAM_CADENA], cadena2[TAM_CADENA];
    char str;
    scanf("%[^\n]s", cadena);
    
    p1 = cadena;
    p2 = cadena2;
    while(*p1 != '\0'){
        if (*p1 > 'a')
        {
            *p2 = *p1 - 32;
        }
        else
        {
            *p2 = *p1;
        }
        p1++;
        p2++;
    }
    *p2 = '\0';

    printf("%s\n", cadena2);
    return 0;
}
