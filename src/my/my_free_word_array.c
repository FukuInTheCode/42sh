/*
** EPITECH PROJECT, 2024
** my_free_word_array.c
** File description:
** my_free_word_array.c
*/

#include "my.h"
#include <stdlib.h>

int my_free_word_array(char **arr)
{
    if (!arr)
        return 0;
    for (size_t i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
