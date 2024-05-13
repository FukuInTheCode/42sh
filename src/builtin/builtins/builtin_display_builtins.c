/*
** EPITECH PROJECT, 2024
** builtin_display_builtins.c
** File description:
** builtin_display_builtins.c
*/

#include "my.h"
#include "builtins.h"

////////////////////////////////////////////////////////////
// int dislpay_builtins(int col_width, int num_col,
// int num_builtins)
//
// col_width -> width of the columns
// num_col -> number of columns
// num_builtins -> number of builtins
//
// This function displays all the builtins of the 42sh.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int dislpay_builtins(int col_width, int num_col, int num_builtins)
{
    for (int i = 0; builtins[i].name != NULL; i++) {
        printf("%-*s", col_width, builtins[i].name);
        if ((i + 1) % num_col == 0 || i == num_builtins - 1)
            printf("\n");
    }
    printf("\n");
    return 0;
}

////////////////////////////////////////////////////////////
// display_builtins_small_terminal(void)
//
// This function displays all the builtins of the 42sh when
// the terminal is small.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int display_builtins_small_terminal(void)
{
    for (int i = 0; builtins[i].name != NULL; i++) {
        printf("%s ", builtins[i].name);
    }
    printf("\n");
    return 0;
}
