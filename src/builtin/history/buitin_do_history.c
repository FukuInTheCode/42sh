/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** buitin_do_history.c
*/

#include "history.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

static int add_in_current(char *current, char c, int index)
{
    if (index == -1 || my_char_is_in_str(c, current))
        return index;
    if (my_char_is_in_str(c, "chrSLMT")) {
        current[index] = c;
        return index + 1;
    }
    return -1;
}

static char *get_flag(char **argv)
{
    char *current = calloc(8, sizeof(char));
    int index = 0;

    for (int i = 1; argv[i] && argv[i][0] == '-'; i++)
        for (int j = 1; argv[i][j]; j++)
            index = add_in_current(current, argv[i][j], index);
    if (index == -1) {
        dprintf(2, "Usage: history [-chrSLMT] [# number of events].\n");
        return (NULL);
    }
    return current;
}

static int get_size(int argc, char **argv)
{
    if (argc == 1 || argv[argc - 1][0] == '-')
        return -1;
    for (int i = 0; argv[argc - 1][i]; i++) {
        if (argv[argc - 1][i] > '9' || argv[argc - 1][i] < '0') {
            dprintf(2, "history: Badly formed number.\n");
            return 0;
        }
    }
    return (atoi(argv[argc - 1]));
}

int builtin_do_history(command_t *command, shell_t *shell)
{
    char *flag;

    if (command->argc > 3) {
        dprintf(2, "history: Too many arguments.\n");
        return 1;
    }
    flag = get_flag(command->argv);
    if (flag == NULL)
        return 1;
    if (my_char_is_in_str('c', flag))
        remove_history(shell);
    if (my_char_is_in_str('S', flag)) {
        save_history(shell->history, command->argv, command->argc);
        free(flag);
        return 0;
    }
    display_history(shell->history, flag, get_size(command->argc, command->argv));
    free(flag);
    return 0;
}
