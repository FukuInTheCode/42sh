/*
** EPITECH PROJECT, 2024
** display_command
** File description:
** display_command
*/

#include "autocompletion.h"
#include "my.h"
#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include "env.h"

static int indice_init(int lenght)
{
    if (lenght < 18)
        return 5;
    if (lenght < 40)
        return 4;
    if (lenght < 100)
        return 3;
    return 2;
}

void display_space(char *argument, int max_lenght)
{
    int lenght = strlen(argument);

    for (int i = 0; i < max_lenght - lenght; i++) {
        printf(" ");
    }
}

void display_command(char **command, int size)
{
    int telltale = 1;
    int lenght = find_max_lenght(command);

    if (size == 0)
        return;
    printf("\n");
    for (size_t i = 0; command[i] != NULL; i++) {
        printf("%s", command[i]);
        if (my_len_word_array(command) - 1 != i)
            display_space(command[i], lenght);
        if (telltale == indice_init(lenght)) {
            printf("\n");
            telltale = 0;
        }
        telltale++;
    }
    if (telltale != 1)
        printf("\n");
    printf("$> ");
}
