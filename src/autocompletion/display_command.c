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

void display_space(char *argument, int max_lenght)
{
    int lenght = strlen(argument);

    for (int i = 0; i < max_lenght - lenght; i++) {
        printf(" ");
    }
}

void display_command(char **command)
{
    int telltale = 1;
    int lenght = find_max_lenght(command);

    if (command == NULL)
        return;
    for (int i = 0; command[i] != NULL; i++) {
        printf("%s", command[i]);
        if (telltale == 6) {
            printf("\n");
            telltale = 0;
        } else
            display_space(command[i], lenght);
        telltale++;
    }
    if (telltale != 1)
        printf("\n");
}
