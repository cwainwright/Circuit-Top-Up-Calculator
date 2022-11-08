/* Monetary Function Definitions */

#include <stdio.h>
#include <stdlib.h>

int set_money(char message[]) {
  /* Asks for two int values (pounds and pence),
  returns monetary value (in pence)*/
  int pounds, pence, res;
  fputs(message, stdout);
  res = scanf("%d.%2d", &pounds, &pence);
  
  if (pence >= 100 || res==EOF || res<2) {
    printf("Invalid input\n");
    exit(EXIT_FAILURE);
  }
  return (100*pounds+pence);
}

void get_money(int value) {
  /* Takes int value (in pence), outputs (in pounds and pence) */
  int pounds, pence;
  pounds = value/100;
  pence = value%100;
  printf("£%d.%02d", pounds, pence);
}