/*
** EPITECH PROJECT, 2024
** parser_command_and.c
** File description:
** parser_command_and.c
*/

#include "my.h"

static bool token_is_empty(char const *s)
{
    if (!s)
        return true;
    for (size_t i = 0; s[i]; i++)
        if (s[i] != ' ' && s[i] != '\t')
            return false;
    return true;
}

static int set_next(parser_t *parser, command_t *my_or)
{
    command_t *next = NULL;

    if (parser_handle_separator(parser, parser->tokens[parser->index + 1]))
        return 0;
    if (!parser->tokens[parser->index + 1])
        return 0;
    parser_set_index(parser, parser_get_index(parser) + 1);
    if (token_is_empty(parser->tokens[parser->index]))
        return 0;
    next = parser_command_command(parser);
    command_add(my_or, next);
    return 0;
}

command_t *parser_command_or(parser_t *parser, command_t *prev)
{
    command_t *ret = NULL;
    char **argv = NULL;

    if (!parser)
        return NULL;
    ret = command_create();
    if (!ret)
        return NULL;
    command_set_type(ret, OR);
    argv = my_str_to_word_array(parser->tokens[parser->index], "");
    if (!argv) {
        command_destroy(ret);
        return NULL;
    }
    command_set_argv(ret, argv);
    set_next(parser, ret);
    if (prev && command_get_type(prev) == COMMAND)
        command_set_wait(prev, true);
    return ret;
}
