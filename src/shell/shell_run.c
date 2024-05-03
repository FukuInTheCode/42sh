/*
** EPITECH PROJECT, 2024
** shell_set_run.c
** File description:
** shell_set_run.c
*/

#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int shell_run(shell_t *shell)
{
    char *line = NULL;
    size_t len = 0;

    shell_handle_prompt(shell);
    for (; getline(&line, &len, stdin) != -1; shell_handle_prompt(shell)) {
        shell_clean(shell);
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        shell_process_input(shell, line);
        if (shell_get_exit(shell))
            break;
    }
    free(line);
    return 0;
}
