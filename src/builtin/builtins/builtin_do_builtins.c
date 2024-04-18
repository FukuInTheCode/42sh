/*
** EPITECH PROJECT, 2024
** builtin_do_builtins.c
** File description:
** builtin_do_builtins.c
*/

#include "my.h"
#include "builtins.h"
#include <sys/ioctl.h>

int dislpay_builtins(int col_width, int num_col, int num_builtins)
{
    for (int i = 0; builtins[i].name != NULL; i++) {
        printf("%-*s", col_width, builtins[i].name);
        if ((i + 1) % num_col == 0 || i == num_builtins - 1)
            printf("\n");
    }
    printf("\n");
    return 0;
}

int get_num_col(int num_col, int num_builtins,
    int max_col_width, int size_terminal)
{
    if (num_col > num_builtins)
        num_col = num_builtins;
    if (num_col * max_col_width > size_terminal)
        num_col = size_terminal / max_col_width;
    return num_col;
}

int display_builtins_little_terminal(void)
{
    for (int i = 0; builtins[i].name != NULL; i++) {
        printf("%s ", builtins[i].name);
    }
    printf("\n");
    return 0;
}

int if_terminal_to_little(shell_t *shell)
{
    display_builtins_little_terminal();
    shell_set_code(shell, 1);
    return 0;
}

int builtin_do_builtins(command_t *command, shell_t *shell)
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
        return if_terminal_to_little(shell);
    num_col = size_terminal / min_col_width;
    num_col = get_num_col(num_col, num_builtins, max_col_width, size_terminal);
    col_width = size_terminal / num_col;
    if (command == NULL || shell == NULL)
        return 84;
    dislpay_builtins(col_width, num_col, num_builtins);
    shell_set_code(shell, 0);
    return 0;
}
