#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void suma(int num1, int num2);
void resta(int num1, int num2);

void main (int argc, char **argv){
 
  if (argc != 4){
   printf(" Error.\n son necessaris 4 arguments: %s operacio op1 op2", argv[0]);
   exit(1);
  }
  if (strcmp("suma", argv[1]) == 0)
    suma(atoi(argv[2]), atoi(argv[3]));
  else
    if (strcmp("resta", argv[1]) == 0)
    resta(atoi(argv[2]), atoi(argv[3]));
    else
      printf("OperaciÃ³ no permesa\n");
}

void suma(int num1, int num2)
{
  printf(" resultat  de l'operacio --> %d + %d = %d\n", num1, num2, num1 + num2);
}

void resta(int num1, int num2)
{
  printf(" resultat  de l'operacio --> %d - %d = %d\n", num1, num2, num1 - num2);
}