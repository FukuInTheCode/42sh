/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** input_handling.c
*/

#include <line_edition.h>

line_edition_t *init_edition(void)
{
    line_edition_t *edition = malloc(sizeof(line_edition_t));

    if (!edition)
        return NULL;
    edition->line = malloc(sizeof(char) * 3 + 1);
    if (!edition->line)
        return NULL;
    return edition;
}
