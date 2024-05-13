/*
** EPITECH PROJECT, 2024
** builtin_display_where.c
** File description:
** builtin_display_where.c
*/

#include "my.h"
#include "builtins.h"
#include <string.h>

static bool have_caract(char *argv)
{
    char *caract = strstr(argv, "/");

    if (caract != NULL)
        return true;
    return false;
}

bool display_where_builtin(char *argv)
{
    if (is_builtin(argv)) {
        printf("%s: shell built-in command.\n", argv);
        return true;
    }
    return false;
}

bool display_where_command_not_found(bool found, shell_t *shell)
{
    if (found == false)
        shell_set_code(shell, 1);
    return true;
}

int display_where_with_invalid_caract(char *argv, shell_t *shell)
{
    if (have_caract(argv)) {
        dprintf(2, "where: / in command makes no sense\n");
        shell_set_code(shell, 1);
        return 1;
    }
    return 0;
}
