#include <stdio.h>

int Number;
#define N 10

int main(int argc, char const *argv[])
{
    int i;

    Number = N;

    printf(" The first %d natural numbers are:\n", Number);
    
    for(i = 0; i < Number; i++)
    {
        printf("    %d \n", i);
    }
    
    printf("BYE\n");
    return 0;
}
