/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define MY_H

    #include <stddef.h>
    #include <signal.h>
    #include <stdbool.h>

    #include "error.h"

typedef enum type_e {
    COMMAND,
    PIPELINE,
    AND,
    OR,
    SUBSHELL_OPEN,
    SUBSHELL_CLOSE,
    LEFT_RED,
    RIGHT_RED,
    DOUBLE_LEFT_RED,
    DOUBLE_RIGHT_RED,
    OTHER,
    END
} type_t;

typedef struct command_s {
    int argc;
    char **argv;
    type_t type;
    int out;
    int in;
    int err;
    bool do_wait;
    int status;
    pid_t pid;
    char *path;
    struct command_s *next;
    struct command_s *prev;
} command_t;

command_t *command_create(void);
int command_destroy(command_t *);
command_t *command_copy(command_t *);

int command_set_argc(command_t *, int);
int command_set_argv(command_t *, char **);
int command_set_type(command_t *, type_t);
int command_set_out(command_t *, int);
int command_set_in(command_t *, int);
int command_set_err(command_t *, int);
int command_set_pid(command_t *, pid_t);
int command_set_next(command_t *, command_t *);
int command_set_prev(command_t *, command_t *);
int command_set_status(command_t *, int);
int command_set_wait(command_t *, bool);
int command_set_path(command_t *, char const *);

int command_get_argc(command_t *);
char **command_get_argv(command_t *);
type_t command_get_type(command_t *);
int command_get_out(command_t *);
int command_get_in(command_t *);
int command_get_err(command_t *);
int command_get_status(command_t *);
bool command_get_wait(command_t *);
command_t *command_get_next(command_t *);
command_t *command_get_prev(command_t *);
pid_t command_get_pid(command_t *);
char *command_get_path(command_t *);

int command_add(command_t *, command_t *);
int command_exec(command_t *, void *);
int command_wait(command_t *, void *);
int command_process_exec_error(command_t *, void *);
int command_process_out(command_t *, void *);
int command_process_in(command_t *, void *);
int command_process_err(command_t *, void *);
int command_process_status(command_t *, void *);
int command_process_status_error(command_t *, void *);
int command_handle_pipe(command_t *, command_t *, void *);
int command_handle_right_red(command_t *, command_t *, void *);
int command_handle_double_right_red(command_t *, command_t *, void *);
int command_handle_left_red(command_t *, command_t *, void *);
int command_handle_double_left_red(command_t *, command_t *, void *);
int command_handle_fork(command_t *);
int command_handle_opens(command_t *);
int command_handle_closes(command_t *, void *);
int command_process_user_errors(command_t *, void *);
int command_process_null_error(command_t *, command_t *, void *);
int command_process_path(command_t *, void *);
int command_process_builtins(command_t *, void *);
int command_handle_builtins(command_t *);

int command_handle_null_error(command_t *, void *);
int command_handle_output_error(command_t *, void *);
int command_handle_input_error(command_t *, void *);
int command_handle_name_error(command_t *, void *);
int command_handle_badly_error(command_t *, void *);
int command_handle_toomanyopen_error(command_t *, void *);
int command_handle_toomanyclose_error(command_t *, void *);

int command_handle_arch_error(void *, int);
int command_handle_found_error(void *, int);
int command_handle_perm_error(void *, int);
int command_handle_dir_error(void *, int);
int command_handle_longname_error(void *, int);
int command_handle_loop_error(void *, int);

int command_handle_segfault_error(void *, int);
int command_handle_segfault_coredumped_error(void *, int);

int command_handle_file_exist_error(command_t *, void *);
int command_handle_file_perm_error(command_t *, void *);

static myerror_t const status_errors[] = {
    {"Segmentation fault (core dumped)\n",
        command_handle_segfault_coredumped_error},
    {"Segmentation fault\n", command_handle_segfault_error},
    {NULL, NULL}
};

static myerror_t const user_errors[] = {
    {"Too many ('s.\n", command_handle_toomanyopen_error},
    {"Too many )'s.\n", command_handle_toomanyclose_error},
    {"Missing name for redirect.\n", command_handle_name_error},
    {"Ambiguous output redirect.\n", command_handle_output_error},
    {"Ambiguous input redirect.\n", command_handle_input_error},
    {"Badly placed ()'s.\n", command_handle_badly_error},
    {NULL, NULL}
};

static myerror_t const exec_errors[] = {
    {": Command not found.\n", command_handle_found_error},
    {": Permission denied.\n", command_handle_perm_error},
    {": Is a directory.\n", command_handle_dir_error},
    {": Exec format error. Wrong Architecture.\n", command_handle_arch_error},
    {": File name too long.\n", command_handle_longname_error},
    {": Too many levels of symbolic links.\n", command_handle_loop_error},
    {NULL, NULL}
};
