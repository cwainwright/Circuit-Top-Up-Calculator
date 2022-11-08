#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

/* Monetary Function Definitions */

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

int calculate_washes(int current_balance, int *washcount, int *drycount) {
  /* 
  Takes current_balance, washcount, drycount args
  Returns remaining balance
  */
  int remainder, cyclecount;
  cyclecount = current_balance/(WASHPRICE+DRYPRICE);
  *washcount += cyclecount;
  *drycount += cyclecount;
  remainder = current_balance%(WASHPRICE+DRYPRICE);
  if (remainder >= WASHPRICE) {
    remainder -= WASHPRICE;
    *washcount += 1;
  } else if (remainder >= DRYPRICE) {
    remainder -= DRYPRICE;
    *drycount += 1;
  }
  return remainder;
}

int calculate_top_up(int remainder, int *washcount, int *drycount) {
  int top_up = MINTOPUP;
  remainder += top_up;
  remainder = calculate_washes(remainder, washcount, drycount);
  if (*drycount>*washcount) {
    *washcount += 1;
    top_up += WASHPRICE - remainder;
  } else {
    *drycount += 1;
    top_up += DRYPRICE - remainder;
  }
  return top_up;
}

int calculate_even_split(int *washcount, int *drycount) {
  if (*washcount<*drycount) {
    *washcount += 1;
    return WASHPRICE;
  } else {
    *drycount += 1;
    return DRYPRICE;
  }
}