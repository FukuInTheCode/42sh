/*
** EPITECH PROJECT, 2024
** shell_set_exit.c
** File description:
** shell_set_exit.c
*/

#include "my.h"

int shell_set_exit(shell_t *shell, bool do_exit)
{
    shell->do_exit = do_exit;
    return 0;
}
