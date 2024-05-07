/*
** EPITECH PROJECT, 2024
** parser_set_index.c
** File description:
** parser_set_index.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int parser_set_index(parser_t *parser, size_t index)
//
// parser -> all the data of the parser
// index -> index of the parser
//
// This function sets the index of the parser.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int parser_set_index(parser_t *parser, size_t index)
{
    parser->index = index;
    return 0;
}
