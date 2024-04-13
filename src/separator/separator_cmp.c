/*
** EPITECH PROJECT, 2024
** separator_cmp.c
** File description:
** separator_cmp.c
*/

#include "my.h"

#include <string.h>

bool separator_cmp(separator_t const *sep, char const *s)
{
    if (!s || !sep)
        return false;
    if (strncmp(sep->separator, s, strlen(sep->separator)))
        return false;
    for (size_t i = 0; sep->banned[i]; i++)
        if (!strncmp(sep->banned + i, s + strlen(sep->separator), 1))
            return false;
    return true;
}
