// Program ThreadsAdd.c
// To compile do:
// gcc ThreadsAdd.c -o SeqAdd -lm
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#define DIMROW 1000000
#define NUMROWS 20
#define CORE 4

typedef struct row {
  int vector[DIMROW];
  long addition;
} row;

struct row matrix[NUMROWS];

void *AddRow(void *ptr) {
  int k;
  row *fi;
  fi = (row *)ptr;
  fi->addition = 0;

  for (k = 0; k < DIMROW; k++) {
    fi->addition += exp((k * (fi->vector[k]) +
                         (k + 1) * (fi->vector[k])) /
                        (fi->vector[k] + 2 * k)) /
                    2;
  }
}

void *Efficent(void *cnt) {
  int i;
  int *count;
  count = (int *)cnt;
  for (i = *count; i < *(count + 1); i++) {
    AddRow(&matrix[i]);
  }
}

int main() {
  int i, j;
  long total_addition = 0;
  int iteration_rest = NUMROWS - CORE * (NUMROWS / CORE);
  int increment = NUMROWS / CORE;
  int iteration[CORE + 1];

  for (i = 0; i < CORE + 1; i++)
  {
    iteration[i] = increment * i;
  }

  pthread_t threads[CORE];
  pthread_attr_t atrib;

  // Vector elements are initialized to 1
  for (i = 0; i < NUMROWS; i++) {
    for (j = 0; j < DIMROW; j++) {
      matrix[i].vector[j] = 1;
    }
  }

  // Thread attributes initialization
  pthread_attr_init(&atrib);
  // EXERCISE 2.a
  for (i = 0; i < CORE; i++) {
    if (iteration_rest > 0) {
      iteration[i]++;
      iteration_rest--;
    }
    pthread_create(&threads[i], &atrib, Efficent, &iteration[i]);
  }

  // EXERCISE 2.b
  for (i = 0; i < CORE; i++) {
    pthread_join(threads[i], NULL);
  }

  for (i = 0; i < NUMROWS; i++)
    total_addition += matrix[i].addition;
  printf("Total addition is: %ld \n", total_addition);
}