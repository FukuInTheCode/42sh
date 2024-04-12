/*
** EPITECH PROJECT, 2024
** command_set_argv.c
** File description:
** command_set_argv.c
*/

#include "my.h"

int command_set_argv(command_t *command, char **argv)
{
    my_free_word_array(command->argv);
    command->argv = argv;
    command_set_argc(command, my_len_word_array(argv));
    return 0;
}
