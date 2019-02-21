/* my_child.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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
    wait(NULL);
    return 0;
}