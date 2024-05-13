/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** my_char_is_in_str.c
*/

int my_char_is_in_str(char c, char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}
