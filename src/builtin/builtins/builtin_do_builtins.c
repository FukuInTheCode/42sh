/*
** EPITECH PROJECT, 2024
** builtin_do_builtins.c
** File description:
** builtin_do_builtins.c
*/

#include "my.h"
#include "builtins.h"
#include <sys/ioctl.h>

int get_num_col(int num_col, int num_builtins,
    int max_col_width, int size_terminal)
{
    if (num_col > num_builtins)
        num_col = num_builtins;
    if (num_col * max_col_width > size_terminal)
        num_col = size_terminal / max_col_width;
    return num_col;
}

int if_terminal_to_small(shell_t *shell)
{
    display_builtins_small_terminal();
    shell_set_code(shell, 1);
    return 0;
}

int get_size_col(shell_t *shell)
{
    int num_builtins = sizeof(builtins) / sizeof(builtins[0]);
    int size_terminal = 0;
    int min_col_width = 5;
    int max_col_width = 15;
    int num_col = 0;
    int col_width = 0;
    struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
    size_terminal = w.ws_col;
    if (size_terminal == 0)
        return if_terminal_to_small(shell);
    num_col = size_terminal / min_col_width;
    num_col = get_num_col(num_col, num_builtins, max_col_width, size_terminal);
    col_width = size_terminal / num_col;
    dislpay_builtins(col_width, num_col, num_builtins);
    return 0;
}

int builtin_do_builtins(command_t *command, shell_t *shell)
{
    int argc = 0;

    if (command == NULL || shell == NULL)
        return 84;
    argc = command_get_argc(command);
    if (argc != 1) {
        fprintf(stderr, "builtins: Too many arguments\n");
        return shell_set_code(shell, 1);
    }
    shell_set_code(shell, 0);
    return get_size_col(shell);
}
