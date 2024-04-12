/*
** EPITECH PROJECT, 2024
** parser_set_index.c
** File description:
** parser_set_index.c
*/

#include "my.h"

int parser_set_index(parser_t *parser, size_t index)
{
    parser->index = index;
    return 0;
}
