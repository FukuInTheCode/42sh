/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** history.h
*/

#pragma once
    #define HISTORY_H

    #include "shell.h"

void remove_history(shell_t *);

void display_history(history_t *, char *, int);

void add_in_history(history_t **, char *, shell_t *);

void save_history(history_t *history, char **argv, int argc);
