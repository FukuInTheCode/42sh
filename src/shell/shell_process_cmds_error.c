/*
** EPITECH PROJECT, 2024
** shell_process_cmds_error.c
** File description:
** shell_process_cmds_error.c
*/

#include "command.h"
#include "my.h"

int shell_process_cmds_error(shell_t *shell)
{
    command_t *head = shell_get_cmds(shell);
    command_t *start = head;
    type_t type = 0;

    for (; head; head = command_get_next(head)) {
        if (command_process_user_errors(head, (void *)shell) == 1)
            return 1;
        type = command_get_type(head);
        if (type != PIPELINE && type != END)
            continue;
        if (command_process_null_error(start, head, (void *)shell) == 1)
            return 1;
        start = head;
    }
    if (start && command_process_null_error(start, NULL, (void *)shell) == 1)
        return 1;
    return 0;
}
