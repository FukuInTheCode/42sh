/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** my_str_is
*/

int my_char_in_str(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}