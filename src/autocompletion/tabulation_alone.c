/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** tabulation_alone
*/

#include "autocompletion.h"
#include "my.h"
#include "shell.h"
#include "env.h"
#include <stdlib.h>

#include <dirent.h>

char **command_find_loop_dir(DIR *dir, char *arg,
    int **buffer_size, char *path)
{
    struct dirent *entry;
    char **str = my_str_to_word_array(arg, "/");
    char **buff = NULL;
    char *temp = NULL;

    entry = readdir(dir);
    buff = command_realloc(buff, buffer_size[0]);
    while (entry != NULL) {
        if (entry->d_name[0] != '.') {
            temp = is_directory_or_exec(entry->d_name, path, arg);
            buff = buffer_add(buff, temp, buffer_size);
        }
        entry = readdir(dir);
    }
    buff[(*buffer_size)[1]] = NULL;
    my_free_word_array(str);
    closedir(dir);
    return buff;
}

int find_space(char *arg)
{
    if (arg[0] == '\0')
        return 0;
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == ' ')
            return 1;
    }
    return 0;
}

char **tabulation_alone(char *arg, shell_t *shell, char *buff)
{
    DIR *dir;
    char **buffer = NULL;
    int *buffer_size = calloc(sizeof(int) * 2, sizeof(int) * 2);

    if (strchr(buff, ' ') == NULL && buff[0] != '\0') {
        free(buffer_size);
        buffer = search_command(arg, shell);
        return buffer;
    }
    dir = opendir(".");
    if (dir == NULL)
        perror("opendir");
    if (buff[strlen(buff) - 1] != ' ')
        buffer = command_find_loop(dir, arg, &buffer_size, ".");
    else
        buffer = command_find_loop_dir(dir, "", &buffer_size, ".");
    free(buffer_size);
    return buffer;
}
