/*
** EPITECH PROJECT, 2024
** find_lenght
** File description:
** find_lenght
*/

#include "autocompletion.h"

int find_max_lenght(char **arguments)
{
    int lenght = 0;
    int temp = 0;

    for (int i = 0; arguments[i] != NULL; i++) {
        temp = strlen(arguments[i]);
        if (temp > lenght)
            lenght = temp;
    }
    return lenght + 5;
}
