/*
** EPITECH PROJECT, 2024
** parser_create.c
** File description:
** parser_create.c
*/

#include "my.h"

#include <stdlib.h>

////////////////////////////////////////////////////////////
// parser_t *parser_create(void)
//
// This function does necessary memory allocations to the
// parser.
//
// RETURN VALUE : parser_t * with the memory allocation.
// NULL if an error occurs
////////////////////////////////////////////////////////////
parser_t *parser_create(void)
{
    parser_t *parser = calloc(1, sizeof(parser_t));

    if (!parser)
        return NULL;
    parser->tokens = calloc(1, sizeof(char *));
    if (!parser->tokens) {
        free(parser);
        return NULL;
    }
    return parser;
}
