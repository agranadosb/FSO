#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void)
{
    pid_t valor;

    int X = 10;

    int Y = 8;

    valor = fork();

    if (valor > 0)
    {
        printf("Padre %d\n", getpid());
        sleep(X);
    }
    else
    {
        printf("Hijo de %d\n", getppid());
        sleep(Y);
    }

    return 0;
}