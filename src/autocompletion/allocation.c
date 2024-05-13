/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** allocation
*/
#include "autocompletion.h"
#include "my.h"
#include <stdlib.h>

char **command_realloc(char **buffer, int *buffer_size)
{
    char **temp = my_copy_word_array(buffer);

    if (buffer == NULL)
        *buffer_size = 0;
    else {
        *buffer_size = my_len_word_array(buffer);
    }
    temp = realloc(temp, sizeof(char *) * (*buffer_size + 2));
    if (temp == NULL)
        perror("realloc");
    my_free_word_array(buffer);
    return temp;
}

char **allocation_of_buffer(char **buffer, char **result)
{
    char **temp = my_copy_word_array(buffer);

    if (temp == NULL) {
        temp = malloc(sizeof(char *) * ((my_len_word_array(result) + 1)));
        temp = memset(temp, 0, sizeof(char *)
            * ((my_len_word_array(result) + 1)));
    }
    temp = my_cat_word_array(temp, result);
    my_free_word_array(buffer);
    return temp;
}
