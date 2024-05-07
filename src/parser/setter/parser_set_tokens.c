/*
** EPITECH PROJECT, 2024
** parser_set_tokens.c
** File description:
** parser_set_tokens.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// int parser_set_tokens(parser_t *parser, char **tokens)
//
// parser -> all the data of the parser
// tokens -> arrays of tokens
//
// This function sets the tokens of the parser.
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int parser_set_tokens(parser_t *parser, char **tokens)
{
    parser->tokens = tokens;
    return 0;
}
