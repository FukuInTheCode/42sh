/*
** EPITECH PROJECT, 2024
** builtin_display_where.c
** File description:
** builtin_display_where.c
*/

#include "my.h"
#include "builtins.h"

bool display_where_builtin(char *argv)
{
    if (is_builtin(argv)) {
        printf("%s: shell built-in command.\n", argv);
        return true;
    }
    return false;
}

bool display_where_command_not_found(char *argv, bool found, shell_t *shell)
{
    if (found == false) {
        dprintf(2, "%s: Command not found.\n", argv);
        shell_set_code(shell, 1);
    }
    return true;
}