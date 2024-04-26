/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define MY_H
    #define _GNU_SOURCE

    #include <stdio.h>

    #include "shell.h"
    #include "command.h"
    #include "parser.h"
    #include "separator.h"

void my_swap(char *a, char *b);
//int my_free_word_array(char **);
int my_char_in_str(char c, char *str);
char **my_str_to_word_array(char *, char const *);
size_t my_len_word_array(char **);
