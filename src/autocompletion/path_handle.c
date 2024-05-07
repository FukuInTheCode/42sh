/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** path_handle
*/

#include "autocompletion.h"
#include "my.h"
#include "env.h"
#include <stdlib.h>
#include <string.h>

char **path_handle(char *arg, shell_t *shell)
{
    char **temp = my_str_to_word_array(arg, " ");
    char **send = NULL;
    char *full_path = strdup(env_get(shell_get_env(shell), "PATH"));
    char *result = strdup(full_path);
    //int indice = my_len_word_array(temp);
    
    /*
    if (indice != 1) {
        result = strcat(full_path, ":");
        result = strcat(full_path, temp[indice - 1]);
    }*/
    result = realloc(result, strlen(full_path) + strlen(":.") + 1);
    strcat(result, ":.");
    my_free_word_array(temp);
    send = my_str_to_word_array(result, ":");
    free(full_path);
    free(result);
    return send;
}