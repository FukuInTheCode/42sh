/*
** EPITECH PROJECT, 2024
** shell_process_subshell.c
** File description:
** shell_process_subshell.c
*/

#include "shell.h"
#include "command.h"
#include "env.h"
#include "my.h"
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

static command_t *find_end_subshell(command_t *cmd)
{
    size_t subshell_count = 0;

    for (; cmd; cmd = command_get_next(cmd)) {
        if (command_get_type(cmd) == SUBSHELL_OPEN)
            subshell_count++;
        if (command_get_type(cmd) == SUBSHELL_CLOSE)
            subshell_count--;
        if (subshell_count == 0)
            return cmd;
    }
    return NULL;
}

static int copy_commands(shell_t *subshell, command_t *cmd, command_t *end)
{
    command_t *copy = NULL;

    for (cmd = command_get_next(cmd); cmd &&
        cmd != end; cmd = command_get_next(cmd)) {
        copy = command_copy(cmd);
        if (!copy)
            return 84;
        if (shell_get_cmds(subshell))
            command_add(shell_get_cmds(subshell), copy);
        if (!shell_get_cmds(subshell))
            shell_set_cmds(subshell, copy);
    }
    return 0;
}

static int init_subshell(shell_t *subshell, command_t *start,
    command_t *end, shell_t *shell)
{
    if (!subshell || !start || !end || !shell)
        return 84;
    shell_set_env(subshell, env_copy(shell_get_env(shell)));
    command_process_in(end, shell);
    command_process_out(end, shell);
    command_process_err(end, shell);
    if (command_get_in(start) != shell_get_in(shell))
        shell_set_in(subshell, command_get_in(start));
    else
        shell_set_in(subshell, command_get_in(end));
    shell_set_out(subshell, command_get_out(end));
    shell_set_err(subshell, command_get_err(end));
    if (shell_get_out(subshell) == shell_get_out(shell))
        shell_set_out(subshell, dup(shell_get_out(shell)));
    if (shell_get_in(subshell) == shell_get_in(shell))
        shell_set_in(subshell, dup(shell_get_in(shell)));
    if (shell_get_err(subshell) == shell_get_err(shell))
        shell_set_err(subshell, dup(shell_get_err(shell)));
    return 0;
}

static int run_subshell(shell_t *subshell, shell_t *shell)
{
    pid_t pid = fork();
    int code = 0;

    if (pid != 0) {
        waitpid(pid, &code, 0);
        shell_set_code(shell, code);
        return 0;
    }
    shell_process_commands(subshell);
    shell_set_exit(shell, true);
    return 0;
}

int shell_process_subshell(shell_t *shell, command_t *cmd, command_t **curr)
{
    shell_t *subshell = NULL;
    command_t *close_end = NULL;

    if (!shell || !cmd || !curr || !*curr)
        return 84;
    close_end = find_end_subshell(cmd);
    if (!close_end)
        return 84;
    subshell = shell_create();
    init_subshell(subshell, cmd, close_end, shell);
    copy_commands(subshell, cmd, close_end);
    run_subshell(subshell, shell);
    shell_destroy(subshell);
    *curr = close_end;
    return 0;
}
