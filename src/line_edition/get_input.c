/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** get_input.c
*/

#include <line_edition.h>

////////////////////////////////////////////////////////////
// int display_input(char *buffer, int *i, char c)
//
// buffer -> current buffer to the command line
// i -> index of the cursor
// c -> current character
//
// This function prints the current character according to the key
// pressed.
//
// RETURN VALUE : none.
////////////////////////////////////////////////////////////
void display_input(char *buffer, int *i, char c)
{
    if (handle_special_char(buffer, i, c) == 1)
        return;
    printf("\033[1@");
    printf("%c", c);
    do_str_right_shift(buffer, *i - 1);
    buffer[*i] = c;
    *i = *i + 1;
}

////////////////////////////////////////////////////////////
// char *get_input(void)
//
// This function launches the instance that allow to modify the
// buffer using the arrows.
//
// RETURN VALUE : char * that represent the buffer, NULL if an
// error occurs.
////////////////////////////////////////////////////////////
char *get_input(void)
{
    size_t buffer_size = MAX_INPUT;
    char *buffer = calloc(sizeof(char) * buffer_size, sizeof(char));
    char c;
    int i = 0;

    if (!buffer) {
        perror("Memory allocation error");
        return NULL;
    }
    set_noncanonical_mode();
    while (1) {
        if (extend_buffer(&buffer, &buffer_size) == 84)
            return NULL;
        c = getchar();
        if (c == '\n')
            break;
        else
            display_input(buffer, &i, c);
    }
    return buffer;
}
