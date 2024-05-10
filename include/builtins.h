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
int builtin_do_history(command_t *, shell_t *);
int builtin_do_builtins(command_t *, shell_t *);
int builtin_do_which(command_t *, shell_t *);
int builtin_do_set(command_t *, shell_t *);
int builtin_do_unset(command_t *, shell_t *);
int builtin_do_where(command_t *, shell_t *);
int builtin_do_repeat(command_t *, shell_t *);
int builtin_do_at(command_t *, shell_t *);
int builtin_do_alias(command_t *, shell_t *);
int builtin_do_alloc(command_t *, shell_t *);
int builtin_do_bg(command_t *, shell_t *);
int builtin_do_bindkey(command_t *, shell_t *);
int builtin_do_break(command_t *, shell_t *);
int builtin_do_breaksw(command_t *, shell_t *);
int builtin_do_case(command_t *, shell_t *);
int builtin_do_complete(command_t *, shell_t *);
int builtin_do_continue(command_t *, shell_t *);
int builtin_do_default(command_t *, shell_t *);
int builtin_do_dirs(command_t *, shell_t *);
int builtin_do_echotc(command_t *, shell_t *);
int builtin_do_else(command_t *, shell_t *);
int builtin_do_end(command_t *, shell_t *);
int builtin_do_endif(command_t *, shell_t *);
int builtin_do_endsw(command_t *, shell_t *);
int builtin_do_eval(command_t *, shell_t *);
int builtin_do_exec(command_t *, shell_t *);
int builtin_do_fg(command_t *, shell_t *);
int builtin_do_filetest(command_t *, shell_t *);
int builtin_do_foreach(command_t *, shell_t *);
int builtin_do_glob(command_t *, shell_t *);
int builtin_do_goto(command_t *, shell_t *);
int builtin_do_hashstat(command_t *, shell_t *);
int builtin_do_hup(command_t *, shell_t *);
int builtin_do_if(command_t *, shell_t *);
int builtin_do_jobs(command_t *, shell_t *);
int builtin_do_limit(command_t *, shell_t *);
int builtin_do_log(command_t *, shell_t *);
int builtin_do_login(command_t *, shell_t *);
int builtin_do_logout(command_t *, shell_t *);
int builtin_do_nice(command_t *, shell_t *);
int builtin_do_while(command_t *, shell_t *);
int builtin_do_wait(command_t *, shell_t *);
int builtin_do_unlimit(command_t *, shell_t *);
int builtin_do_unhash(command_t *, shell_t *);
int builtin_do_uncomplete(command_t *, shell_t *);
int builtin_do_unalias(command_t *, shell_t *);
int builtin_do_umask(command_t *, shell_t *);
int builtin_do_time(command_t *, shell_t *);
int builtin_do_termname(command_t *, shell_t *);
int builtin_do_telltc(command_t *, shell_t *);
int builtin_do_switch(command_t *, shell_t *);
int builtin_do_suspend(command_t *, shell_t *);
int builtin_do_stop(command_t *, shell_t *);
int builtin_do_source(command_t *, shell_t *);
int builtin_do_shift(command_t *, shell_t *);
int builtin_do_setty(command_t *, shell_t *);
int builtin_do_settc(command_t *, shell_t *);
int builtin_do_sched(command_t *, shell_t *);
int builtin_do_rehash(command_t *, shell_t *);
int builtin_do_pushd(command_t *, shell_t *);
int builtin_do_popd(command_t *, shell_t *);
int builtin_do_onintr(command_t *, shell_t *);
int builtin_do_notify(command_t *, shell_t *);
int builtin_do_nohup(command_t *, shell_t *);
int builtin_do_echo(command_t *, shell_t *);

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
char *get_to_do_variable(char **a, int i, char *);
int set_destroy(shell_t *);
void remove_node_linked_list_set(shell_t *shell, char *assigned);
bool display_where_builtin(char *);
bool display_where_command_not_found(bool found, shell_t *);
int display_where_with_invalid_caract(char *, shell_t *);

static builtin_t const builtins[] = {
    {":", builtin_do_colon},
    {"@", builtin_do_at},
    {"alias", builtin_do_alias},
    {"alloc", builtin_do_alloc},
    {"bg", builtin_do_bg},
    {"bindkey", builtin_do_bindkey},
    {"break", builtin_do_break},
    {"breaksw", builtin_do_breaksw},
    {"builtins", builtin_do_builtins},
    {"case", builtin_do_case},
    {"cd", builtin_do_cd},
    {"chdir", builtin_do_cd},
    {"complete", builtin_do_complete},
    {"continue", builtin_do_continue},
    {"default", builtin_do_default},
    {"dirs", builtin_do_dirs},
    {"echo", builtin_do_echo},
    {"echotc", builtin_do_echotc},
    {"else", builtin_do_else},
    {"end", builtin_do_end},
    {"endif", builtin_do_endif},
    {"endsw", builtin_do_endsw},
    {"eval", builtin_do_eval},
    {"exec", builtin_do_exec},
    {"exit", builtin_do_exit},
    {"fg", builtin_do_fg},
    {"filetest", builtin_do_filetest},
    {"foreach", builtin_do_foreach},
    {"glob", builtin_do_glob},
    {"goto", builtin_do_goto},
    {"hashstat", builtin_do_hashstat},
    {"history", builtin_do_history},
    {"hup", builtin_do_hup},
    {"if", builtin_do_if},
    {"jobs", builtin_do_jobs},
    {"limit", builtin_do_limit},
    {"log", builtin_do_log},
    {"login", builtin_do_login},
    {"logout", builtin_do_logout},
    {"nice", builtin_do_nice},
    {"nohup", builtin_do_nohup},
    {"notify", builtin_do_notify},
    {"onintr", builtin_do_onintr},
    {"popd", builtin_do_popd},
    {"printenv", builtin_do_printenv},
    {"pushd", builtin_do_pushd},
    {"rehash", builtin_do_rehash},
    {"repeat", builtin_do_repeat},
    {"sched", builtin_do_sched},
    {"set", builtin_do_set},
    {"setenv", builtin_do_setenv},
    {"settc", builtin_do_settc},
    {"setty", builtin_do_setty},
    {"shift", builtin_do_shift},
    {"source", builtin_do_source},
    {"stop", builtin_do_stop},
    {"suspend", builtin_do_suspend},
    {"switch", builtin_do_switch},
    {"telltc", builtin_do_telltc},
    {"termname", builtin_do_termname},
    {"time", builtin_do_time},
    {"umask", builtin_do_umask},
    {"unalias", builtin_do_unalias},
    {"uncomplete", builtin_do_uncomplete},
    {"unhash", builtin_do_unhash},
    {"unlimit", builtin_do_unlimit},
    {"unset", builtin_do_unset},
    {"unsetenv", builtin_do_unsetenv},
    {"wait", builtin_do_wait},
    {"where", builtin_do_where},
    {"which", builtin_do_which},
    {"while", builtin_do_while},
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
