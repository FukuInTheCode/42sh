/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** autocompletion
*/

#pragma once
    #define AUTOCOMPLETION_H_

    #include <string.h>
    #include <dirent.h>
    #include "shell.h"

char **search_command(char *, shell_t *);
char **tabulation_alone(char *, shell_t *);
char **command_find_loop(DIR *, char *, int **, char *);

int find_max_lenght(char **);
int find_space(char *);

void display_command(char **);
void set_command_auto_completion(char **);
void my_qsort(char **, size_t);
void autocomplete_buffer(char **, char *);