#include <stdio.h>

int x = 2;
void m();

void main()
{
    int x = 3;
    m();
    printf("%d\n", x);
}

void m()
{
    x=4;
}