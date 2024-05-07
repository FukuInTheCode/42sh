/*
** EPITECH PROJECT, 2024
** shell_parse_input.c
** File description:
** shell_parse_input.c
*/

#include "my.h"
#include "parser.h"
#include <stdio.h>

////////////////////////////////////////////////////////////
// int shell_parse_input(shell_t *shell, char const *input)
//
// shell -> structure that contains all the data of the shell
// input -> string that represent the input of the user
//
// This function parse and process the input and set the
// commands into the shell
//
// RETURN VALUE : int that is always 0
////////////////////////////////////////////////////////////
int shell_parse_input(shell_t *shell, char const *input)
{
    parser_t *parser = parser_create();

    parser_parse(parser, input);
    shell_set_cmds(shell, parser_to_command(parser));
    parser_destroy(parser);
    return 0;
}
