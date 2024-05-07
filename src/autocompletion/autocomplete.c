/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** autocomplete
*/

#include "autocompletion.h"
#include <stdio.h>

void autocomplete_buffer(char **buffer, char *arg)
{
    int lenght = strlen(arg);

    printf("%s", arg);
    for (size_t i = lenght; strlen(buffer[0]) > i; i++) {
        printf("%c", buffer[0][i]);
    }
}
