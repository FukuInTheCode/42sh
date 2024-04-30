/*
** EPITECH PROJECT, 2024
** variables.h
**
** File description:
** .h for the variables
*/

#pragma once
    #define VARIABLES_H

    #include "shell.h"
    #include <stdio.h>
    #include <string.h>

typedef struct variables_s {
    char *assigned;
    char *need_to_do;
    struct variables_s *next;
} variables_t;

char *variables_format(char const *, shell_t *);
