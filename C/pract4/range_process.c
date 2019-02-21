/* my_child.c */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i, aux;
    for(i = 0; i < 5; i++)
    {
        aux = fork();
        if (aux == 0) {
            printf("Fill creat en iteració=%d\n", i + 1);
            exit(0);
        }
    }
    sleep(10);
    exit(0);
    return 0;
}