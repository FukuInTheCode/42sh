/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** display_history.c
*/

#include "builtins.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void display_history(history_t *history, char *flag, int nb_elt_display)
{
    struct tm *time;

    if (!history || nb_elt_display == 0)
        return;
    if (history->next && !my_char_is_in_str('r', flag))
        display_history(history->next, flag, nb_elt_display - 1);
    if (!my_char_is_in_str('h', flag)) {
        time = localtime(&history->time);
        printf("\t%i\t%i:", history->id, time->tm_hour);
        if (time->tm_min < 10)
            printf("0");
        printf("%i\t", time->tm_min);
    } else if (my_char_is_in_str('T', flag))
        printf("#+%li\n", history->time);
    printf("%s\n", history->line);
    if (history->next && my_char_is_in_str('r', flag))
        display_history(history->next, flag, nb_elt_display - 1);
}
