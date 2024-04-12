/*
** EPITECH PROJECT, 2024
** command_process_builtins.c
** File description:
** command_process_builtins.c
*/

#include "my.h"
#include "builtins.h"
#include "string.h"

int command_process_builtins(command_t *command, void *shell)
{
    for (size_t i = 0; builtins[i].f; i++) {
        if (!strcmp(command_get_path(command), builtins[i].name)) {
            builtins[i].f(command, shell);
            return 1;
        }
    }
    return 0;
}
