/*
** EPITECH PROJECT, 2024
** error_put.c
** File description:
** error_put.c
*/

#include "my.h"

#include <stdio.h>

int error_put(myerror_t *error)
{
    dprintf(2, "%s", error->err);
    return 0;
}
