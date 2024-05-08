/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** autocomplete
*/

#include "autocompletion.h"
#include "my.h"
#include <stdio.h>
#include "env.h"
#include <stdlib.h>
#include <string.h>

char **path_handle(char *arg, shell_t *shell)
{
    char **temp = my_str_to_word_array(arg, " ");
    char **send = NULL;
    char *full_path = strdup(env_get(shell_get_env(shell), "PATH"));
    char *result = strdup(full_path);

    result = realloc(result, strlen(full_path) + strlen(":.") + 1);
    strcat(result, ":.");
    my_free_word_array(temp);
    send = my_str_to_word_array(result, ":");
    free(full_path);
    free(result);
    return send;
}

char *autocomplete_buffer(char **buffer, int len, int *i)
{
    printf("\033[%dD", len + 3);
    printf("$> ");
    printf("%s", buffer[0]);
    *i = (int)strlen(buffer[0]);
    return buffer[0];
}

char *autocompletion(char *buffer, shell_t *shell, int *i)
{
    char **commands = NULL;
    int len = 0;

    commands = tabulation_alone(buffer, shell);
    if (my_len_word_array(commands) != 1)
        display_command(commands, my_len_word_array(commands), buffer);
    else if (strncmp(buffer, commands[0], strlen(commands[0])) != 0) {
        len = (int)strlen(buffer);
        memset(buffer, 0, sizeof(char) * (int)strlen(buffer));
        strcat(buffer, autocomplete_buffer(commands, len, i));
    }
    return buffer;
}
