/*
** EPITECH PROJECT, 2024
** parser_get_quote.c
** File description:
** parser_get_quote.c
*/

#include "my.h"
////////////////////////////////////////////////////////////
// bool parser_get_quote(parser_t *parser)
//
// parser -> all the data of the parser
//
// This function returns the quote status of the parser.
//
// RETURN VALUE : bool that is the status of the quote
// in the parser
////////////////////////////////////////////////////////////
bool parser_get_quote(parser_t *parser)
{
    return parser->in_quote;
}
