/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** history.h
*/

#pragma once
    #define HISTORY_H

    #include "shell.h"

    #define HISTORY_FILE_NAME ".history"

void remove_history(shell_t *);

history_t *copy_history(history_t *);

void add_in_history(shell_t *, char *);

void save_history(shell_t *, char *);

void display_history(history_t *, char *, int);

void history_load_from_file(shell_t *, char *);
