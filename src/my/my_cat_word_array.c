/*
** EPITECH PROJECT, 2024
** 42sh-mirror
** File description:
** my_cat_word_array
*/

#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char **last_part(int i, char **result, char **arr2, int len2)
{
    int j = 0;

    for (j = 0; j < len2; j++) {
        result[i + j] = strdup(arr2[j]);
        if (result[i + j] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
    }
    return result;
}

static void find_length(int *len1, int *len2, char **arr1, char **arr2)
{
    int telltale1 = 0;
    int telltale2 = 0;

    if (arr1 == NULL) {
        (*len1) = 0;
        telltale1 = 1;
    }
    if (arr2 == NULL) {
        (*len2) = 0;
        telltale2 = 1;
    }
    while (arr1 != NULL && arr1[*len1] != NULL && telltale1 != 1)
        (*len1)++;
    while (arr2 != NULL && arr2[*len2] != NULL && telltale2 != 1)
        (*len2)++;
}

static char **first_part(int *i, int len1, char **result, char **arr1)
{
    for (*i = 0; *i < len1; (*i)++) {
        result[*i] = strdup(arr1[*i]);
        if (result[*i] == NULL) {
            dprintf(2, "Memory allocation failed\n");
            return NULL;
        }
    }
    return result;
}

char **my_cat_word_array(char **arr1, char **arr2)
{
    int len1 = 0;
    int len2 = 0;
    char **result;
    int i = 0;

    if (arr1 == NULL || arr2 == NULL)
        return NULL;
    find_length(&len1, &len2, arr1, arr2);
    result = (char **)malloc((len1 + len2 + 1) * sizeof(char *));
    if (result == NULL) {
        dprintf(2, "Memory allocation failed\n");
        return NULL;
    }
    result = first_part(&i, len1, result, arr1);
    result = last_part(i, result, arr2, len2);
    result[len1 + len2] = NULL;
    return result;
}
