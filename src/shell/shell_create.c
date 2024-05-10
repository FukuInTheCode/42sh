/*
** EPITECH PROJECT, 2024
** shell_create.c
** File description:
** shell_create.c
*/

#include "builtins.h"
#include "env.h"
#include "my.h"
#include "history.h"
#include <stdlib.h>
#include <unistd.h>

static void init_special_vars(shell_t *shell)
{
    char *tmp = getlogin();

    if (!tmp)
        return;
    add_linked_list_set("user", tmp, shell);
    add_linked_list_set("shell", "42sh", shell);
    add_linked_list_set("status", "0", shell);
    add_linked_list_set("42sh", "1.0.0 closed alpha", shell);
    add_linked_list_set("prompt", "$> ", shell);
    add_linked_list_set("cdtohome", "cd ~", shell);
    add_linked_list_set("version", "42sh Epitech Promo 2028", shell);
}

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
    shell->head = NULL;
    init_special_vars(shell);
    shell_set_out(shell, SYS_OUT);
    shell_set_err(shell, SYS_ERR);
    shell_set_history_id(shell, 0);
    shell_set_history(shell, NULL);
    history_load_from_file(shell, HISTORY_FILE_NAME);
    return shell;
}
