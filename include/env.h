/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define ENV_H

char **env_copy(char **);
char *env_get(char **, char const *);
char **env_add(char **, char const *, char const *);
char **env_change(char **, char const *, char const *);
char **env_remove(char **, char const *);
int env_destroy(char **);
