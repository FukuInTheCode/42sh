/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "my.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static bool change_is_quote(bool is_quote)
{
    if (is_quote)
        return false;
    return true;
}

static int get_nb_of_word(char *str, char const *del)
{
    bool is_quote = false;
    int nb = 1;
    char quote = ' ';

    for (int i = 0; str[i + 1] != '\0'; i++) {
        if ((str[i] == '"' && (quote == ' ' || quote == '"')) ||
        (str[i] == '\'' && (quote == ' ' || quote == '\''))) {
            is_quote = change_is_quote(is_quote);
            quote = str[i];
        }
        if (is_quote == false)
            quote = ' ';
        if (my_char_is_in_str(str[i], del) &&
        !my_char_is_in_str(str[i + 1], del) && !is_quote)
            nb++;
    }
    if (my_char_is_in_str(str[0], del))
        nb--;
    return nb;
}

static int count_size_of_word(char *str, int i, char const *del)
{
    bool is_quote = false;
    int nb = i;
    int quote_nb = 0;
    char quote = ' ';

    while ((!my_char_is_in_str(str[nb], del) || is_quote == true) && str[nb]) {
        if ((str[nb] == '"' && (quote == ' ' || quote == '"')) ||
        (str[nb] == '\'' && (quote == ' ' || quote == '\''))) {
            is_quote = change_is_quote(is_quote);
            quote = str[nb];
            quote_nb++;
        }
        if (is_quote == false)
            quote = ' ';
        nb++;
    }
    return (nb - i - quote_nb);
}

static int get_size_of_word_with_quote(char *str, int i, char const *del)
{
    int nb = i;
    bool is_quote = false;
    char quote = ' ';

    while ((!my_char_is_in_str(str[nb], del) || is_quote == true) && str[nb]){
        if ((str[nb] == '"' && (quote == ' ' || quote == '"')) ||
        (str[nb] == '\'' && (quote == ' ' || quote == '\''))) {
            is_quote = change_is_quote(is_quote);
            quote = str[nb];
        }
        if (is_quote == false)
            quote = ' ';
        nb++;
    }
    return (nb - i);
}

static int change_i(int i, char *str, char const *del)
{
    while (my_char_is_in_str(str[i], del))
        i++;
    return i;
}

static char **my_str_to_word_array_malloc(int nb_of_word)
{
    char **word_array;

    if (nb_of_word == 0)
        return NULL;
    word_array = calloc(nb_of_word + 1, sizeof(char *));
    if (word_array == NULL)
        return NULL;
    return word_array;
}

static char *add_in_word_array(int word_size, int i, char *str)
{
    char *word = calloc(word_size + 1, sizeof(char));
    int quote_nb = 0;
    char quote = ' ';
    bool is_quote = false;

    if (word == NULL)
        return NULL;
    for (int j = i; (j - i) < word_size + quote_nb; j++) {
        if (is_quote == false)
            quote = ' ';
        if ((str[j] == '"' && (quote == ' ' || quote == '"')) ||
        (str[j] == '\'' && (quote == ' ' || quote == '\''))) {
            is_quote = change_is_quote(is_quote);
            quote = str[j];
            quote_nb++;
            continue;
        }
        word[j - i - quote_nb] = str[j];
    }
    return word;
}

char **my_str_to_word_array(char *str, char const *del)
{
    int size = strlen(str);
    char **word_array = my_str_to_word_array_malloc(get_nb_of_word(str, del));
    int ind = 0;
    int word_size;

    if (word_array == NULL)
        return (NULL);
    for (int i = 0; i < size; i += word_size + 1) {
        i = change_i(i, str, del);
        word_size = count_size_of_word(str, i, del);
        word_array[ind] = add_in_word_array(word_size, i, str);
        if (word_array[ind] == NULL)
            return NULL;
        word_size = get_size_of_word_with_quote(str, i, del);
        ind++;
    }
    return (word_array);
}
