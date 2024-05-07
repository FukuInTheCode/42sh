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
    #include <unistd.h>
    #include <termios.h>
    #include <string.h>
    #include <shell.h>

#define MAX_INPUT 1024
#define LEFT 68
#define RIGHT 67
#define DOWN 66
#define TOP 65
#define SUPPR 126
#define BACKSPACE 127

typedef struct line_edition_s {
    char *line;
} line_edition_t;

void restore_terminal(void);
void set_noncanonical_mode(void);

line_edition_t *init_edition(void);

char *get_input(shell_t *shell);

int extend_buffer(char **buffer, size_t *buffer_size);

int handle_special_char(char **buffer, int *i, char c, shell_t *shell);

void do_str_left_shift(char *words, size_t n);
void do_str_right_shift(char *words, int n);
