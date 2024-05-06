/*
** EPITECH PROJECT, 2024
** parser_set_dblquote.c
** File description:
** parser_set_dblquote.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int parser_set_dblquote(parser_t *parser, bool quote)
//
// parser -> all the data of the parser
// quote -> status of double quote presence
//
// This function sets the double quote status of the parser.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int parser_set_dblquote(parser_t *parser, bool quote)
{
    parser->in_double_quote = quote;
    return 0;
}
