#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool startsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : strncmp(pre, str, lenpre) == 0;
}

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < argc; i++)
    {

        if (strcmp("-c", argv[i]) == 0)
        {
            printf("Argumento %d es Compilar\n", i);
        }
        else if (strcmp("-E", argv[i]) == 0)
        {
            printf("Argumento %d es Preprocesar\n", i);
        }
        else if (startsWith("-i" , argv[i]))
        {
            printf("Argumento %d es Incluir %s\n", i, argv[i] + 2);
        }
    }

    return 0;
}
