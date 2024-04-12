/*
** EPITECH PROJECT, 2024
** parser_set_tokens.c
** File description:
** parser_set_tokens.c
*/

#include "my.h"

int parser_set_tokens(parser_t *parser, char **tokens)
{
    parser->tokens = tokens;
    return 0;
}
