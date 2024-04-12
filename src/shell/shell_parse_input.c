/*
** EPITECH PROJECT, 2024
** shell_parse_input.c
** File description:
** shell_parse_input.c
*/

#include "my.h"
#include "parser.h"
#include <stdio.h>

int shell_parse_input(shell_t *shell, char const *input)
{
    parser_t *parser = parser_create();

    parser_parse(parser, input);
    shell_set_cmds(shell, parser_to_command(parser));
    parser_destroy(parser);
    return 0;
}
