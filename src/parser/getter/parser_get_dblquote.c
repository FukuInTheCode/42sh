/*
** EPITECH PROJECT, 2024
** parser_get_dblquote.c
** File description:
** parser_get_dblquote.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// bool parser_get_dblquote(parser_t *parser)
//
// parser -> all the data of the parser
//
// This function returns the double quote status of the parser.
//
// RETURN VALUE : bool that is the status of the double quote
// in the parser
////////////////////////////////////////////////////////////
bool parser_get_dblquote(parser_t *parser)
{
    return parser->in_double_quote;
}
