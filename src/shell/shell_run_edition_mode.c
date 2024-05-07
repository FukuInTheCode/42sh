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

    while (!shell_get_exit(shell)) {
        shell_handle_prompt(shell);
        line = get_input(shell);
        if (!line) {
            return 84;
        }
        printf("\n");
        shell_process_input(shell, line);
        free(line);
        shell_clean(shell);
        restore_terminal();
    }
    return 0;
}
