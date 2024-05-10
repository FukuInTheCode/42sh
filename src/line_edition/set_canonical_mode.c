/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** set_canonical_mode
*/

#include "line_edition.h"

void restore_terminal(void)
{
    struct termios t;

    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}
