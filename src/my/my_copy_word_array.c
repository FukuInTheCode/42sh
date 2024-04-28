/*
** EPITECH PROJECT, 2024
** my_copy_word_array.c
** File description:
** my_copy_word_array.c
*/

#include "my.h"
#include <string.h>
#include <stdlib.h>

char **my_copy_word_array(char **arr)
{
    char **copy = NULL;

    if (!arr)
        return NULL;
    copy = calloc(my_len_word_array(arr) + 1, sizeof(char *));
    if (!copy)
        return NULL;
    for (size_t i = 0; arr[i]; i++) {
        copy[i] = strdup(arr[i]);
        if (!copy[i]) {
            my_free_word_array(copy);
            return NULL;
        }
    }
    return copy;
}
