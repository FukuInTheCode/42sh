/*
** EPITECH PROJECT, 2024
** builtin_display_builtins.c
** File description:
** builtin_display_builtins.c
*/

#include "my.h"
#include "builtins.h"

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

int display_builtins_small_terminal(void)
{
    for (int i = 0; builtins[i].name != NULL; i++) {
        printf("%s ", builtins[i].name);
    }
    printf("\n");
    return 0;
}
