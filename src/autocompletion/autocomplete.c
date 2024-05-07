/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** autocomplete
*/

#include "autocompletion.h"
#include "my.h"
#include <stdio.h>

char *autocomplete_buffer(char **buffer, char *arg)
{
    int lenght = strlen(arg);

    printf("\033[%dD", lenght);
    printf("%s", arg);
    printf("%s", *buffer + lenght);
    printf("\033[%dC", (int)strlen(*buffer) - lenght);
    return buffer[0];
}

char *autocompletion(char *buffer, shell_t *shell)
{
    char **commands = NULL;

    commands = tabulation_alone(buffer, shell);
    if (my_len_word_array(commands) != 1)
        display_command(commands, my_len_word_array(commands));
    else if (strncmp(buffer, commands[0], strlen(commands[0])) != 0)
        buffer = autocomplete_buffer(commands, buffer);
    return buffer;
}
