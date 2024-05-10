/*
** EPITECH PROJECT, 2024
** parser_command_open_subshell.c
** File description:
** parser_command_open_subshell.c
*/

#include "command.h"
#include "my.h"
#include "parser.h"

command_t *parser_command_open_subshell(parser_t *parser)
{
    command_t *ret = NULL;
    char **argv = NULL;

    if (!parser)
        return NULL;
    ret = command_create();
    if (!ret)
        return NULL;
    command_set_type(ret, SUBSHELL_OPEN);
    argv = my_str_to_word_array(parser->tokens[parser->index], "");
    if (!argv) {
        command_destroy(ret);
        return NULL;
    }
    command_set_argv(ret, argv);
    return ret;
}
