/*
** EPITECH PROJECT, 2024
** builtin_do_set.c
** File description:
** builtin_do_set.c
*/

#include "my.h"
#include "variables.h"
#include "builtins.h"
#include "shell.h"

int get_if_error(shell_t *shell, char *assigned)
{
    if (assigned == NULL)
        return 0;
    if (!(assigned[0] >= 'a' && assigned[0] <= 'z')
        && (!(assigned[0] >= 'A' && assigned[0] <= 'Z'))) {
        dprintf(2, "set: Variable name must begin with a letter.\n");
        shell_set_code(shell, 1);
        return 84;
    }
    return 0;
}

int builtin_do_set(command_t *command, shell_t *shell)
{
    char **argv = NULL;
    char *assigned = NULL;
    char *need_to_do = NULL;

    if (command == NULL || shell == NULL)
        return 84;
    argv = command_get_argv(command);
    for (int i = 1; i < command->argc; i++) {
        assigned = NULL;
        need_to_do = NULL;
        assigned = get_assigned_variable(argv, &i, assigned);
        need_to_do = get_to_doux_variable(argv, i, need_to_do);
        if (get_if_error(shell, assigned) == 84)
            return 1;
        add_linked_list_set(assigned, need_to_do, shell);
    }
    return 0;
}
