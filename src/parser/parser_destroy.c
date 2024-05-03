/*
** EPITECH PROJECT, 2024
** parser_destroy.c
** File description:
** parser_destroy.c
*/

#include "my.h"

#include <stdlib.h>

int parser_destroy(parser_t *parser)
{
    my_free_word_array(parser->tokens);
    free(parser);
    return 0;
}
