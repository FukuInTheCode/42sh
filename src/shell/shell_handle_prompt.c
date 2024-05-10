/*
** EPITECH PROJECT, 2024
** shell_handle_prompt.c
** File description:
** shell_handle_prompt.c
*/

#include "my.h"
#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

////////////////////////////////////////////////////////////
// int shell_handle_prompt(shell_t *shell)
//
// shell -> structure that contains all the data of the shell
//
// This function handles and print the prompt "$>" when is
// necessary.
//
// RETURN VALUE : int that represent the status of the execution
// the program return 84 when an error occurs, and return 0
// if all works correctly.
////////////////////////////////////////////////////////////
int shell_handle_prompt(shell_t *shell)
{
    if (!shell)
        return 84;
    if (!isatty(0))
        return 0;
    for (variables_t *tmp = shell->head; tmp; tmp = tmp->next) {
        if (strcmp(tmp->assigned, "prompt") || !tmp->to_do)
            continue;
        printf("%s", tmp->to_do);
        return 0;
    }
    return 0;
}
