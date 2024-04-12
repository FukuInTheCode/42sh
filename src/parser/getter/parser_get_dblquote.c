/*
** EPITECH PROJECT, 2024
** parser_get_dblquote.c
** File description:
** parser_get_dblquote.c
*/

#include "my.h"

bool parser_get_dblquote(parser_t *parser)
{
    return parser->in_double_quote;
}
