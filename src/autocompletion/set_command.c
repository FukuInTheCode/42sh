/*
** EPITECH PROJECT, 2024
** set_command
** File description:
** set_command
*/

#include "my.h"
#include "autocompletion.h"

void set_command_auto_completion(char **commands)
{
    if (my_len_word_array(commands) == 1)
        printf("%s", commands[0]);
    else
        display_command(commands);
}