/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define PARSER_H

    #include <stddef.h>
    #include <stdbool.h>

    #include "command.h"
    #include "separator.h"


typedef struct parser_s {
    char **tokens;
    size_t index;
    bool in_quote;
    bool in_double_quote;
} parser_t;

typedef command_t *(command_f_t)();

parser_t *parser_create(void);
int parser_destroy(parser_t *);

int parser_set_tokens(parser_t *, char **);
int parser_set_index(parser_t *, size_t);
int parser_set_quote(parser_t *, bool);
int parser_set_dblquote(parser_t *, bool);

bool parser_get_quote(parser_t *);
bool parser_get_dblquote(parser_t *);
char **parser_get_tokens(parser_t *);
size_t parser_get_index(parser_t *);

int parser_parse(parser_t *, char const *);
command_t *parser_to_command(parser_t *);

separator_t const *parser_handle_separator(parser_t *, char const *);

command_t *parser_command_end(parser_t *);
command_t *parser_command_pipe(parser_t *);
command_t *parser_command_left(parser_t *);
command_t *parser_command_right(parser_t *);
command_t *parser_command_double_left(parser_t *);
command_t *parser_command_double_right(parser_t *);
command_t *parser_command_command(parser_t *);
command_t *parser_command_other(parser_t *, char const *);
command_t *parser_command_and(parser_t *, command_t *);

static separator_t const separators[] = {
    {";", "", parser_command_end},
    {"|", "", parser_command_pipe},
    {">", ">", parser_command_right},
    {">>", "", parser_command_double_right},
    {"<", "<", parser_command_left},
    {"<<", "", parser_command_double_left},
    {"&&", "", parser_command_and},
    {NULL, NULL, NULL}
};
