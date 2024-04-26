/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** my_swap
*/

void my_swap(char *a, char *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}