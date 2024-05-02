/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** lib
*/

#include "my.h"

#include <stdlib.h>
#include <string.h>

char **split_string_at_index(const char *str, int index)
{
    char **parts = (char **)malloc(2 * sizeof(char *));

    if (parts == NULL)
        return NULL;
    parts[0] = (char *)malloc((index + 1) * sizeof(char));
    if (parts[0] == NULL) {
        free(parts);
        return NULL;
    }
    strncpy(parts[0], str, index);
    parts[0][index] = '\0';
    parts[1] = strdup(str + index);
    if (parts[1] == NULL) {
        free(parts[0]);
        free(parts);
        return NULL;
    }
    return parts;
}

int *find_quotes(char *str)
{
    int *quotes = 0;
    int telltale = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\'') {
            quotes[telltale] = i;
            telltale++;
        }
    }
    return quotes;
}

int count(char *s, char c)
{
    int res = 0;
 
    for (size_t i = 0; i < strlen(s); i++) {
        if (s[i] == c)
            res++;
    }
    return res;
}

char **search_of_quotes(char **buffer, int buffer_size, char *str)
{
    char **result = NULL;
    int telltale = 0;

    result = (char **)malloc((buffer_size + 1) * sizeof(char *));
    if (result == NULL)
        return NULL;
    result = split_string_at_index(str, find_quotes)
    for (int i = 0; buffer[i] != NULL; i++) {
        if (i != 0 && count(buffer[i - 1], '\'') == 1 && count(buffer[i], '\'') == 1) {
            result[telltale] = strdup(buffer[i]);
            telltale++;
        }
    }
    result[telltale] = NULL;
}

char **my_str_to_word_array_single_quote(char *str, char *del) 
{
    char **buffer = NULL;
    int buffer_size = 0;

    if (count(str, '\'') == 0) {
        buffer = my_str_to_word_array(str, del);
        return buffer;
    }
    buffer = my_str_to_word_array(str, "\'");
    while (buffer[buffer_size] != NULL) {
        buffer_size++;
    }

    my_free_word_array(buffer);
    return result;
}

int main(void)
{
    char **buffer = my_str_to_word_array_single_quote("coucou haha 'World je' suis moins content Hello", " ");

    for (int i = 0; buffer[i] != NULL; i++) {
        printf("buffer : (%s)\n", buffer[i]);
    }
}