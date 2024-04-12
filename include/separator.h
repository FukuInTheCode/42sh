/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define SEPARATOR_H

    #include <stdbool.h>

typedef struct separator_s {
    char const *separator;
    char const *banned;
    void *f;
} separator_t;

bool separator_cmp(separator_t const *, char const *);
