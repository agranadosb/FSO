/* my_child.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i, aux, stat_loc;
    for(i = 0; i < 5; i++)
    {
        aux = fork();
        if (aux == 0) {
            printf("Son %ld created in iteration %d\n", (long) getpid(), i);
            sleep(10);
            break
        }
        else {
            printf("Son %ld created in iteration %d\n", (long)getpid(), i);
            printf("I have created a son %ld\n", (long) aux);
        }
        sleep(10);
    }
    /*wait all my sons and make exit*/
    while(wait(&stat_loc) > 0)
    {
        printf("Father % ld iteration %d\n", (long)getpid(), i);
        printf( "My son said %d\n", WEXITSTATUS(stat_loc));
        printf( "My son said %d\n", stat_loc / 256);
    }
    return 0;
}