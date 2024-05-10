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

static int get_size(command_t *command)
{
    int argc = command_get_argc(command);
    char **argv = command_get_argv(command);

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

static void handle_flag(shell_t *shell, command_t *command, char *flag)
{
    if (my_char_is_in_str('c', flag))
        remove_history(shell);
    if (my_char_is_in_str('S', flag) || my_char_is_in_str('M', flag)) {
        if (command_get_argc(command) == 3)
            save_history(shell, command_get_argv(command)[2]);
        else
            save_history(shell, HISTORY_FILE_NAME);
        if (!my_char_is_in_str('M', flag))
            return;
    }
    if (my_char_is_in_str('L', flag) || my_char_is_in_str('M', flag)) {
        if (command_get_argc(command) == 3)
            history_load_from_file(shell, command_get_argv(command)[2]);
        else
            history_load_from_file(shell, HISTORY_FILE_NAME);
        return;
    }
    display_history(shell_get_history(shell), flag, get_size(command));
    return;
}

int builtin_do_history(command_t *command, shell_t *shell)
{
    char *flag;

    if (command_get_argc(command) > 3) {
        dprintf(2, "history: Too many arguments.\n");
        return 1;
    }
    flag = get_flag(command_get_argv(command));
    if (flag)
        handle_flag(shell, command, flag);
    else
        return 1;
    free(flag);
    return 0;
}
