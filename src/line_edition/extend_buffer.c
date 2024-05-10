/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** extend_buffer.c
*/

#include <line_edition.h>

int extend_buffer(char **buffer, shell_t *shell)
{
    if ((int)strlen(*buffer) >= shell->cursor_size - 1) {
        shell->cursor_size = shell->cursor_size + 1024;
        *buffer = realloc(*buffer, shell->cursor_size);
        if (!*buffer) {
            perror("Memory allocation error");
            return 84;
        }
        memset(*buffer, 0, shell->cursor_size);
    }
    return 0;
}
