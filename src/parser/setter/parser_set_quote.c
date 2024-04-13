/*
** EPITECH PROJECT, 2024
** parser_set_quote.c
** File description:
** parser_set_quote.c
*/

#include "my.h"

int parser_set_quote(parser_t *parser, bool quote)
{
    parser->in_quote = quote;
    return 0;
}
