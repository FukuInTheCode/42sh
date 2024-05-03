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

int find_space(char *arg)
{
    if (arg[0] == '\0')
        return 1;
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] != ' ')
            return 0;
    }
    return 1;
}

char **tabulation_alone(char *arg, shell_t *shell)
{
    DIR *dir;
    char **buffer = NULL;
    int *buffer_size = calloc(sizeof(int) * 2, sizeof(int) * 2);

    if (find_space(arg) == 0) {
        buffer = search_command(arg, shell);
        return buffer;
    }
    dir = opendir(".");
    if (dir == NULL)
        perror("opendir");
    buffer = command_find_loop(dir, "", &buffer_size, ".");
    closedir(dir);
    return buffer;
}
