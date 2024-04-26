/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** lib
*/

#include "my.h"

#include <stdlib.h>
#include <string.h>

int count(char *s, char c)
{
    int res = 0;
 
    for (size_t i = 0; i < strlen(s); i++) {
        if (s[i] == c)
            res++;
    }
    return res;
}

static int find_word(char *str, char t, char t2, char t3)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == t || str[i] == t2 || str[i] == t3)
            nb++;
        i++;
    }
    if (str[i - 1] == t || str[i - 1] == t2 || str[i - 1] == t3)
        nb++;
    return nb;
}

char **my_str_to_word_array_single(char *str, char t, char t2, char t3)
{
    int nb = find_word(str, t, t2, t3);
    char **array = malloc(sizeof(char *) * (nb + 1));
    int i = 0;
    int pos = 0;
    int length = 0;

    while (str[i]) {
        length = i - 1;
        while (str[i + 1] != t && str[i + 1] != t2 && str[i + 1] != t3 && str[i + 1] != '\0')
            i++;
        i++;
        array[pos] = malloc(sizeof(char) * (i - length + 3));
        if (!array[pos])
            return NULL;
        array[pos] = strncpy(array[pos], &(str[length + 1]), i - length + 2);
        array[pos][i - length] = '\0';
        pos++;
        if (str[i])
            i++;
    }
    array[pos] = NULL;
    return array;
}

char **my_str_to_word_array_single_quote(char *str, char *del)
{
    char **buffer;

    if (count(str, '\'') <= 1 ) {
        buffer = my_str_to_word_array(str, del);
        return buffer;
    }
    buffer = my_str_to_word_array_single(str, '\'', '\'', '\'');
    for (int i = 0; buffer[i] != NULL; i++) {
        if (count(buffer[i], '\'') == 0)
            buffer[i] = my_str_to_word_array(buffer[i], del);
        //if (i != 0 && (count(buffer[i], '\'') != 2))
        //    i++;
        //if (count(buffer[i - 1], '\'') == 1 && count(buffer[i], '\'') == 1)
        //    i++;
        
    }
    return buffer;
}


int main(void)
{
    char **buffer = my_str_to_word_array_single_quote("coucou haha 'World je' suis moins content Hello", " ");

    for (int i = 0; buffer[i] != NULL; i++) {
        printf("buffer : (%s)\n", buffer[i]);
    }
}