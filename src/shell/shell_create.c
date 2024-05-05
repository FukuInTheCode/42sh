/*
** EPITECH PROJECT, 2024
** shell_create.c
** File description:
** shell_create.c
*/

#include "my.h"

#include <stdlib.h>

////////////////////////////////////////////////////////////
// shell_t *shell_create(void)
//
// This function creates and do necessary memory allocations
// to execute the commands.
//
// RETURN VALUE : shell_t that represent the shell. If an
// error occurs, NULL is returned
////////////////////////////////////////////////////////////
shell_t *shell_create(void)
{
    shell_t *shell = calloc(1, sizeof(shell_t));

    if (!shell)
        return NULL;
    shell_set_env(shell, calloc(1, sizeof(char *)));
    if (!shell->env) {
        free(shell);
        return NULL;
    }
    shell_set_out(shell, SYS_OUT);
    shell_set_err(shell, SYS_ERR);
    return shell;
}
