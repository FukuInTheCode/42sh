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

static void free_autocomplete(char **commands, char **temp, char *save)
{
    my_free_word_array(commands);
    my_free_word_array(temp);
    free(save);
}

char *autocomplete_buffer(char *buffer, int len, int *i)
{
    printf("\033[%dD", len + 3);
    printf("$> ");
    printf("%s", buffer);
    *i = (int)strlen(buffer);
    return buffer;
}

char *complete_command(char *buffer, int *i, char **commands, char *save)
{
    sprintf(buffer, "%s ", commands[0]);
    if (save)
        sprintf(buffer, "%s %s ", save, commands[0]);
    buffer = autocomplete_buffer(buffer, (int)strlen(buffer), i);
    return buffer;
}

char *autocompletion(char *buffer, shell_t *shell, int *i)
{
    char **command = NULL;
    char **temp = my_str_to_word_array(buffer, " ");
    int len = my_len_word_array(temp) - 1;
    char *save = NULL;

    if (temp[0] == NULL) {
        my_free_word_array(temp);
        return buffer;
    }
    save = save_handle(temp);
    command = tabulation_alone(temp[len], shell, buffer);
    if (my_len_word_array(command) != 1)
        display_command(command, my_len_word_array(command), save, temp[len]);
    else if (strncmp(temp[len], command[0], strlen(command[0])) != 0) {
        memset(buffer, 0, sizeof(char) *
            ((int)strlen(buffer) + (int)strlen(temp[len]) + 1));
        buffer = complete_command(buffer, i, command, save);
    }
    free_autocomplete(command, temp, save);
    return buffer;
}
