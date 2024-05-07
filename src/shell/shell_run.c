/*
** EPITECH PROJECT, 2024
** shell_set_run.c
** File description:
** shell_set_run.c
*/

#include "my.h"
#include "history.h"
#include "builtins.h"
#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

////////////////////////////////////////////////////////////
// int shell_run(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function launches the loop of the shell, and executes the prompt,
// input detection and execution and launches all the processes.
//
// RETURN VALUE : int that represent the status of the execution
// the program return 84 when an error occurs, and return 0
// if all works correctly.
////////////////////////////////////////////////////////////
int shell_run(shell_t *shell)
{
    char *line = NULL;
    size_t len = 0;

    if (isatty(STDIN_FILENO))
        return shell_run_edition(shell);
    shell_handle_prompt(shell);
    for (; getline(&line, &len, stdin) != -1; shell_handle_prompt(shell)) {
        shell_clean(shell);
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        add_in_history(shell, line);
        shell_process_input(shell, line);
        if (shell_get_exit(shell))
            break;
    }
    save_history(shell, HISTORY_FILE_NAME);
    free(line);
    return 0;
}
