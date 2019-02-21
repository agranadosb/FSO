#include <stdio.h>
#include <stdlib.h>

#define NUMCOLUMNA 100
#define NUMFILA 100

struct matrix
{
    int index[NUMCOLUMNA][NUMFILA];
    int sumaFila;
    int sumaColumna;
};

int sumaElementos(struct matrix mat) { 
    int res = 0, i, j;
    for (i = 0; i < NUMCOLUMNA; i++)
    {
        for (j = 0; j < NUMFILA; j++)
        {
            res += mat.index[i][j];
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    struct matrix c;
    int i, j;

    for (i = 0; i < NUMCOLUMNA; i++)
    {
        for (j = 0; j < NUMFILA; j++)
        {
            c.index[i][j] = rand();
            printf("%d\n", c.index[i][j]);
        }
    }

    printf("%d\n", sumaElementos(c));

    return 0;
}
