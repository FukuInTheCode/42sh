/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** arrow_react.c
*/

#include <shell.h>
#include <line_edition.h>
#include <autocompletion.h>

int extend_buffer_history(char **buffer, shell_t *shell)
{
    int len = (int)strlen(shell->current_h->line);
    shell->cursor_size = len;

    if (len >= 1024) {
        *buffer = realloc(*buffer, (len + 1) * sizeof(char));
        if (!*buffer) {
            perror("Memory allocation error");
            return 84;
        }
        memset(*buffer, 0, (len + 1) * sizeof(char));
    }
    return 0;
}

void do_arrow_react(char c, int *i, char *buffer, shell_t *shell)
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
    if (edition->line[2] == UP) {
        /*if (shell->current_h) {
            shell->current_h = shell->current_h->next;
        }*/
        if (shell->current_h) {
            printf("\033[%dD", (int)strlen(buffer) + 3);
            printf("\033[K");
            printf("$> ");
            printf("%s", shell->current_h->line);
            memset(buffer, 0, sizeof(char) * strlen(buffer));
            if (extend_buffer_history(&buffer, shell) == 84)
                return;
            strcat(buffer, shell->current_h->line);
            *i = (int)strlen(buffer);
            if (shell->current_h->next) {
                shell->current_h = shell->current_h->next;
            }
        }
    }
    if (edition->line[2] == DOWN) {
        //printf("%s\n", shell->current_h->line);
        if (shell->current_h && shell->current_h->prev) {
            printf("%s\n", shell->current_h->prev->line);
            shell->current_h = shell->current_h->prev;
        }
        if (shell->current_h) {
            printf("%s\n", shell->current_h->line);
        }
        if (shell->current_h && !shell->current_h->prev) {
            printf("\033[%dD", (int)strlen(buffer));
            for (int j = 0; j != (int)strlen(shell->current_h->line); j++)
                printf(" ");
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
        do_arrow_react(c, i, *buffer, shell);
        return 1;
    }
    if (handle_suppr_and_back(buffer, i, c, shell) == 1)
        return 1;
    return 0;
}
