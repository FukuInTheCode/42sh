/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** shell_run_edition_mode.c
*/

#include "my.h"
#include "line_edition.h"
#include <stdio.h>
#include <string.h>

int shell_run_edition(shell_t *shell)
{
    char *line = NULL;

    shell_handle_prompt(shell);
    for (; 1; shell_handle_prompt(shell)) {
        line = get_input();
        if (!line)
            return 84;
        printf("\n");
        restore_terminal();
        shell_clean(shell);
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        shell_process_input(shell, line);
        free(line);
        if (shell_get_exit(shell))
            break;
    }
    return 0;
}
