/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** str_shift.c
*/

#include <line_edition.h>

void do_str_left_shift(char *words, size_t n)
{
    size_t i;
    size_t len = strlen(words);

    for (i = n; i < len; i++)
        words[i - 1] = words[i];
    words[i - 1] = '\0';
}

void do_str_right_shift(char *words, int n)
{
    size_t i;
    size_t len = strlen(words);

    for (i = len; (int)i > n; i--)
        words[i + 1] = words[i];
}
