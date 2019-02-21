#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int i;
    char *arguments1[] = {"ls", "-la", 0};
    char *arguments2[] = {"wc", "-l", 0};
    int fildes[2];
    int fildes_2[2];
    pid_t pid;
    //Parent process creates a pipe
    if ((pipe(fildes) == -1))
    {
        fprintf(stderr, " Pipe failure \n");
        exit(-1);
    }
    if ((pipe(fildes_2) == -1))
    {
        fprintf(stderr, " Pipe failure \n");
        exit(-1);
    }
    for (i = 0; i < 3; i++)
    {
        pid = fork(); //Creates a child process
        if ((pid == 0) && (i == 0))
        {
            if (dup2(fildes[1], STDOUT_FILENO) == -1)
            {
                printf("Error calling dup2\n");
                exit(-1);
            }
            close(fildes[0]);
            close(fildes[1]);
            close(fildes_2[0]);
            close(fildes_2[1]);
            // Child process redirects its output to the pipe
            // Child process closes pipe descriptors
            // Child process changes its memory image
            if (execvp("ls", arguments1) < 0)
            {
                fprintf(stderr, "ls not found \n");
                exit(-1);
            }
        }
        else if ((pid == 0) && (i == 1))
        {
            // Child process redirects its input to the pipe
            // Child process closes pipe descriptors
            // Child process changes its memory image
            if (dup2(fildes[0], STDIN_FILENO) == -1)
            {
                printf("Error calling dup2\n");
                exit(-1);
            }
            close(fildes[0]);
            close(fildes[1]);
            close(fildes_2[0]);
            close(fildes_2[1]);
            if (execlp("grep", "grep", "redir", NULL) < 0)
            {
                fprintf(stderr, "wc not found \n");
                exit(-1);
            }
        }
        else if ((pid == 0) && (i == 2))
        {
            // Child process redirects its input to the pipe
            // Child process closes pipe descriptors
            // Child process changes its memory image
            int fd;
            char *arch = "result.txt";
            mode_t fd_mode = S_IRWXU; // file permissions
            fd = open(arch, O_RDWR | O_CREAT, fd_mode);
            if (dup2(fildes[0], STDIN_FILENO) == -1)
            {
                printf("Error calling dup2\n");
                exit(-1);
            }
            if (dup2(fd, STDOUT_FILENO) == -1)
            {
                printf("Error calling dup2\n");
                exit(-1);
            }
            close(fd);
            close(fildes[0]);
            close(fildes[1]);
            close(fildes_2[0]);
            close(fildes_2[1]);
            if (execvp("wc", arguments2) < 0)
            {
                fprintf(stderr, "wc not found \n");
                exit(-1);
            }
        }
    }

    // Parent process closes pipe descriptors
    close(fildes[0]);
    close(fildes[1]);
    close(fildes_2[0]);
    close(fildes_2[1]);
    for (i = 0; i < 2; i++)
        wait(NULL);
    return (0);
}