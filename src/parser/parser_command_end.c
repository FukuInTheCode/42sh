/*
** EPITECH PROJECT, 2024
** parser_command_end.c
** File description:
** parser_command_end.c
*/

#include "my.h"

command_t *parser_command_end(parser_t *parser)
{
    command_t *ret = NULL;
    char **argv = NULL;

    if (!parser)
        return NULL;
    ret = command_create();
    if (!ret)
        return NULL;
    command_set_type(ret, END);
    argv = my_str_to_word_array(parser->tokens[parser->index], "");
    if (!argv) {
        command_destroy(ret);
        return NULL;
    }
    command_set_argv(ret, argv);
    return ret;
}
