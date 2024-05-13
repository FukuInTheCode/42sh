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
    #include <stdbool.h>

char **directory_close(char *);
char **search_command(char *, shell_t *);
char **tabulation_alone(char *, shell_t *, char *);
char **allocation_of_buffer(char **, char **);
char **command_realloc(char **, int *);
char **buffer_add(char **, char *, int **);
char **command_find_loop(DIR *, char *, int **, char *);
char **path_handle(char *, shell_t *);

char *modify_arg(char *);
char *save_handle(char **);
char *autocompletion(char *, shell_t *, int *);
char *is_directory_or_exec(char *, char *, char *);
char *autocomplete_buffer(char *, int, int *);

int find_max_lenght(char **);
int find_space(char *);

void reset_variables(DIR **, char *, int **);
void display_command(char **, int, char *, char *);
void set_command_auto_completion(char **);
