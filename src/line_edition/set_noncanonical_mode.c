/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** set_noncanonical_mode
*/

#include "../../include/line_edition.h"

void set_noncanonical_mode(void)
{
    struct termios t;

    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}
