#include <stdio.h>
int a = 0;

void inc_a(void);
int valor_anterior(int v);

int main()
{
    int b = 2;
    inc_a();
    valor_anterior(b);
    printf("a = %d, b = %d\n", a, b);
    a++;
    b++;
    inc_a();
    b = valor_anterior(b);
    printf("a = %d, b = %d\n", a, b);
}

void inc_a(void)
{
    a++;
}

int valor_anterior(int v)
{
    int temp;
    temp = v;
    int s = v - 1;
    return s;
}
