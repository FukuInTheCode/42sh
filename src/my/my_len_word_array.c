/*
** EPITECH PROJECT, 2024
** my_len_word_array.c
** File description:
** my_len_word_array.c
*/

#include "my.h"

size_t my_len_word_array(char **arr)
{
    size_t len = 0;

    for (; arr[len]; len++);
    return len;
}
