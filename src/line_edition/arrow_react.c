/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** arrow_react.c
*/

#include <shell.h>
#include <line_edition.h>
#include <autocompletion.h>

void do_arrow_react(char c, int *i, char *buffer)
{
    line_edition_t *edition = init_edition();

    edition->line[0] = c;
    edition->line[1] = getchar();
    edition->line[2] = getchar();
    edition->line[3] = 0;
    if (edition->line[2] == RIGHT) {
        if ((int)strlen(buffer) > *i) {
            printf("\033[1C");
            *i = *i + 1;
        }
    }
    if (edition->line[2] == LEFT) {
        if (*i != 0) {
            printf("\033[1D");
            *i = *i - 1;
        }
    }
    free(edition->line);
    free(edition);
}

static int handle_suppr_and_back(char **buffer, int *i, char c, shell_t *shell)
{
    if (c == BACKSPACE && *i != 0) {
        printf("\033[1D\033[1P");
        do_str_left_shift(*buffer, *i);
        *i = *i - 1;
        return 1;
    }
    if (c == BACKSPACE)
        return 1;
    if (c == 9) {
        *buffer = autocompletion(*buffer, shell, i);
        return 1;
    }
    if (c == SUPPR) {
        printf("\033[1P");
        do_str_left_shift(*buffer, *i + 1);
        return 1;
    }
    return 0;
}

int handle_special_char(char **buffer, int *i, char c, shell_t *shell)
{
    if (c == 27) {
        do_arrow_react(c, i, *buffer);
        return 1;
    }
    if (handle_suppr_and_back(buffer, i, c, shell) == 1)
        return 1;
    return 0;
}
