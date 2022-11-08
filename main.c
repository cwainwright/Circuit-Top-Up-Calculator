#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
  int current_balance, top_up, washcount, drycount, remainder;
  washcount = 0;
  drycount = 0;
  current_balance = set_money("Enter current account balance: £");
  remainder = calculate_washes(current_balance, &washcount, &drycount);

  /* Before top-up */
  printf("\nCurrent Balance:\n");
  printf("Washcount: %d\n", washcount);
  printf("Drycount: %d\n", drycount);
  printf("Remainder: ");
  get_money(remainder);

  /* Calculate top-up */
  top_up = calculate_top_up(remainder, &washcount, &drycount);
  
  /* After top-up */
  printf("\n\nTop Up Details:\n");
  printf("Washcount: %d\n", washcount);
  printf("Drycount: %d\n", drycount);
  printf("Minimum Top Up: ");
  get_money(top_up);

  /* Calculate Even Split */
  if (washcount!=drycount) {
    top_up += calculate_even_split(&washcount, &drycount);
    printf("\n\nEven Split Details:\n");
    printf("Washcount: %d\n", washcount);
    printf("Drycount: %d\n", drycount);
    printf("Top Up: ");
    get_money(top_up);
  }
}
