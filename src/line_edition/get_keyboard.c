/*
** EPITECH PROJECT, 2024
** key_keyborad
** File description:
** get_keyboard
*/

#include "line_edition.h"

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

void find_arrow(line_edition_t *edition, char c)
{
    edition->line[0] = c;
    edition->line[1] = getchar();
    edition->line[2] = getchar();
    edition->line[3] = 0;
    if (edition->line[2] == 67)
//        printf("\nC'est la flêche de droite !\n");
        printf("\033[1C");
    if (edition->line[2] == 66)
        //printf("\nC'est la flêche de bas !\n");
        printf("\033[1P"); // suppr
    if (edition->line[2] == 65) {
        //printf("\nC'est la flêche du haut !\n");
        printf("\033[1D");
        printf("\033[1P");
    }
    if (edition->line[2] == 68)
//        printf("\nC'est la flêche de gauche !\n");
        printf("\033[1D");
}

line_edition_t *getch(line_edition_t *edition)
{
    char c = 'a';

    set_noncanonical_mode();
    while (c != '\n') {
        c = getchar();
        if (c == 27) {
            find_arrow(edition, c);
        } else if (c == 127) {
            printf("\033[1D");
            printf("\033[1P");
        } else if (c == 126) {
            printf("\033[1P");
        } else {
            printf("%c", c);
        }
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


int main(void)
{
    line_edition_t *edition = line_edtion_catch();
    char *line = NULL;
    size_t size = 0;

    getline(&line, &size, stdin);
    printf("%s\n", line);
    free(edition);
    return 0;
}