/*
** EPITECH PROJECT, 2024
** parser_get_index.c
** File description:
** parser_get_index.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// size_t parser_get_index(parser_t *parser)
//
// parser -> all the data of the parser
//
// This function returns the index of the parser.
//
// RETURN VALUE : size_t that is the index of the parser
////////////////////////////////////////////////////////////
size_t parser_get_index(parser_t *parser)
{
    return parser->index;
}
