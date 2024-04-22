/*
** EPITECH PROJECT, 2024
** key_keyborad
** File description:
** get_keyboard
*/

#include "../../include/line_edition.h"

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

line_edition_t *getch(line_edition_t *edition)
{
    char c = 'a';

    set_noncanonical_mode();
    c = getchar();
    if (c == 27) {
        edition->line[0] = c;
        edition->line[1] = getchar();
        edition->line[2] = getchar();
        edition->line[3] = 0;
        restore_terminal();
        return edition;
    }
    restore_terminal();
    return edition;
}

line_edition_t *line_edtion_catch(void)
{
    line_edition_t *edtion = init_edition();

    edtion = getch(edtion);
    return edtion;
}
