/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #include "error.h"
#define ERROR_H

    #include "command.h"
    #include "shell.h"

typedef int(*builtin_func_t)();

typedef struct builtin_s {
    char const *name;
    builtin_func_t f;
} builtin_t;

builtin_t *builtin_get(command_t *);
int builtin_exec(command_t *, shell_t *);

int builtin_do_cd(command_t *, shell_t *);
int builtin_do_setenv(command_t *, shell_t *);
int builtin_do_unsetenv(command_t *, shell_t *);
int builtin_do_printenv(command_t *, shell_t *);
int builtin_do_exit(command_t *, shell_t *);
int builtin_do_colon(command_t *, shell_t *);
int builtin_do_builtins(command_t *, shell_t *);
int builtin_do_which(command_t *, shell_t *);
int builtin_do_set(command_t *, shell_t *);

int builtin_handle_varname_error(shell_t *, char const *);
int builtin_handle_varfirst_error(shell_t *, char const *);

int builtin_handle_cd_errors(shell_t *, char const *, int);
int builtin_handle_cd_access_error(shell_t *, int);
int builtin_handle_cd_dir_error(shell_t *, int);
int builtin_handle_cd_exist_error(shell_t *, int);

int builtin_handle_exit_badnum_error(command_t *, shell_t *);
int builtin_handle_exit_exprsyn_error(command_t *, shell_t *);

int dislpay_builtins(int, int, int);
int display_builtins_small_terminal(void);

bool is_builtin(char *);
bool display_which_builtin(char *);
bool display_which_command_not_found(char *, bool, shell_t *);

void add_linked_list_set(char *, char *, shell_t *);
char *get_assigned_variable(char **, int *, char *);
char *get_to_doux_variable(char **a, int i, char *);

static builtin_t const builtins[] = {
    {":", builtin_do_colon},
    {"builtins", builtin_do_builtins},
    {"cd", builtin_do_cd},
    {"chdir", builtin_do_cd},
    {"exit", builtin_do_exit},
    {"printenv", builtin_do_printenv},
    {"set", builtin_do_set},
    {"setenv", builtin_do_setenv},
    {"unsetenv", builtin_do_unsetenv},
    {"which", builtin_do_which},
    {NULL, NULL}
};

static myerror_t const variables_errors[] = {
    {": Variable name must begin with a letter.\n",
        builtin_handle_varfirst_error},
    {": Variable name must contain alphanumeric characters.\n",
        builtin_handle_varname_error},
    {NULL, NULL}
};

static myerror_t const cd_errors[] = {
    {": Permission denied.\n", builtin_handle_cd_access_error},
    {": No such file or directory.\n", builtin_handle_cd_exist_error},
    {": Not a directory.\n", builtin_handle_cd_dir_error},
    {NULL, NULL}
};

static myerror_t const exit_errors[] = {
    {"exit: Badly formed number.\n", builtin_handle_exit_badnum_error},
    {"exit: Expression Syntax.\n", builtin_handle_exit_exprsyn_error},
    {NULL, NULL}
};
