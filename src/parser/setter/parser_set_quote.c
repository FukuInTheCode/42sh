/*
** EPITECH PROJECT, 2024
** parser_set_quote.c
** File description:
** parser_set_quote.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int parser_set_quote(parser_t *parser, bool quote)
//
// parser -> all the data of the parser
// quote -> status of quote presence
//
// This function sets the quote status of the parser.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int parser_set_quote(parser_t *parser, bool quote)
{
    parser->in_quote = quote;
    return 0;
}
