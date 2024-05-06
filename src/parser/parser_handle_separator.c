/*
** EPITECH PROJECT, 2024
** parser_handle_separator.c
** File description:
** parser_handle_separator.c
*/

#include "my.h"

////////////////////////////////////////////////////////////
// separator_t const *parser_handle_separator(parser_t *parser, char const *token)
//
// parser -> all the data of the parser
// char const *token ->
//
// This function returns the separator search in the token.
//
// RETURN VALUE : separator_t that is the separator founded
////////////////////////////////////////////////////////////
separator_t const *parser_handle_separator(parser_t *parser, char const *token)
{
    if (!parser || !token)
        return NULL;
    for (size_t i = 0; separators[i].separator; i++)
        if (separator_cmp(separators + i, token))
            return separators + i;
    return NULL;
}
