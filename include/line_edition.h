/*
** EPITECH PROJECT, 2024
** line_edition
** File description:
** line_edition
*/

#pragma once
    #define LINE_EDITION_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <termios.h>
    #include <unistd.h>

typedef int(*function_arrows_t)();

typedef struct command_arrow_s{
    char const *name;
    function_arrows_t f;
} command_arrows_t;

typedef struct line_edition_s {
    char *line;
} line_edition_t;

void restore_terminal(void);
void set_noncanonical_mode(void);

line_edition_t *line_edtion_catch(void);

/*
static command_arrows_t const arrows[] = {
    {"^[[C", right_arrow_function},
    {"^[[A", up_arrow_function},
    {"^[[B", down_arrow_function},
    {"^[[D", left_arrow_function},
    {NULL, NULL}
};*/