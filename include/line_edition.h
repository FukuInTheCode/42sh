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

typedef struct line_edition_s {
    char *line;
} line_edition_t;