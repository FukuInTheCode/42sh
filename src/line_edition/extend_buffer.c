/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** extend_buffer.c
*/

#include <line_edition.h>

int extend_buffer(char **buffer, size_t *buffer_size)
{
    if (strlen(*buffer) >= *buffer_size - 1) {
        *buffer_size = *buffer_size + 1024;
        *buffer = realloc(*buffer, *buffer_size);
        if (!*buffer) {
            perror("Memory allocation error");
            return 84;
        }
    }
    return 0;
}
