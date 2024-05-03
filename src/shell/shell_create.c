/*
** EPITECH PROJECT, 2024
** shell_create.c
** File description:
** shell_create.c
*/

#include "my.h"
#include "history.h"

#include <stdlib.h>

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
    shell_set_history_id(shell, 0);
    shell_set_history(shell, NULL);
    history_load_from_file(shell, HISTORY_FILE_NAME);
    return shell;
}
