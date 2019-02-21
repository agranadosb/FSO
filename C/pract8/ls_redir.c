#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int fd;
    char *arch = "output_2.txt";
    mode_t fd_mode = S_IRWXU; // file permissions
    fd = open(arch, O_RDWR | O_CREAT, fd_mode);
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        printf("Error calling dup2\n");
        exit(-1);
    }

    execlp("ls", "ls", "-l", NULL);
    return (0);
}