/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** autocompletion
*/

#pragma once
    #define AUTOCOMPLETION_H_

    #include <string.h>


char **search_command(char *arg);

int find_max_lenght(char **arguments);

void display_command(char **command);
void set_command_auto_completion(char **commands);
