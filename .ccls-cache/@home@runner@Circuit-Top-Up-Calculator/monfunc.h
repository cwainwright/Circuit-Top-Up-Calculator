/* Monetary Function Declarations */

int set_money(char *message);
void get_money(int value);

/* Calculation Function Declarations */
int calculate_washes(int current_balance, int *washcount, int *drycount);
int calculate_top_up(int remainder, int *washcount, int *drycount);
int calculate_even_split(int *washcount, int *drycount);