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

////////////////////////////////////////////////////////////
// int shell_run_edition(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function launches the loop of the shell, and executes the prompt,
// input detection and execution and launches all the processes but
// with line edition mode.
//
// RETURN VALUE : int that represent the status of the execution
// the program return 84 when an error occurs, and return 0
// if all works correctly.
////////////////////////////////////////////////////////////
int shell_run_edition(shell_t *shell)
{
    char *line = NULL;

    while (!shell_get_exit(shell)) {
        shell_handle_prompt(shell);
        line = get_input();
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
