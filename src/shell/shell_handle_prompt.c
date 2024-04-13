/*
** EPITECH PROJECT, 2024
** shell_handle_prompt.c
** File description:
** shell_handle_prompt.c
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>

int shell_handle_prompt(shell_t *shell)
{
    if (!shell)
        return 84;
    if (!isatty(0))
        return 0;
    printf("$> ");
    return 0;
}
