/*
** EPITECH PROJECT, 2024
** command_exec.c
** File description:
** command_exec.c
*/

#include "my.h"

#include <unistd.h>

static int handle_fds(command_t *command, void *shell)
{
    int error = 0;

    error |= command_process_path(command, shell);
    error |= command_process_out(command, shell);
    error |= command_process_err(command, shell);
    error |= command_process_in(command, shell);
    if (error)
        shell_set_code(shell, 1);
    return error;
}

static int exec_builtins(command_t *command, void *shell)
{
    if (command_handle_builtins(command))
        command_process_builtins(command, shell);
    return 0;
}

int command_exec(command_t *command, void *shell)
{
    int do_skip = 0;

    if (!shell || !command)
        return 84;
    do_skip = handle_fds(command, shell);
    command_handle_fork(command);
    if (command_get_pid(command) == 0) {
        command_handle_opens(command);
        exec_builtins(command, shell);
        if (!do_skip && !command_handle_builtins(command)) {
            execve(command_get_path(command),
                command_get_argv(command), shell_get_env(shell));
            command_process_exec_error(command, shell);
        }
        if (command_get_out(command) != 1 || !command_handle_builtins(command))
            shell_set_exit(shell, true);
    }
    command_handle_closes(command);
    return 0;
}
