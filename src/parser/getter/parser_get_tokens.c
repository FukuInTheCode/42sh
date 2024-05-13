/*
** EPITECH PROJECT, 2024
** parser_get_tokens.c
** File description:
** parser_get_tokens.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// char **parser_get_tokens(parser_t *parser)
//
// parser -> all the data of the parser
//
// This function returns the tokens of the parser.
//
// RETURN VALUE : char ** that is the tokens of the parser
////////////////////////////////////////////////////////////
char **parser_get_tokens(parser_t *parser)
{
    return parser->tokens;
}
