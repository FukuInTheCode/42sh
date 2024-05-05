/*
** EPITECH PROJECT, 2024
** error_put.c
** File description:
** error_put.c
*/

#include "my.h"

#include <stdio.h>

////////////////////////////////////////////////////////////
// int error_put(myerror_t *error)
//
// error -> structure that contains all the data about the error
//
// This function prints the error expected.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int error_put(myerror_t *error)
{
    dprintf(2, "%s", error->err);
    return 0;
}
