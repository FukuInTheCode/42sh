/*
** EPITECH PROJECT, 2024
** parser_parse.c
** File description:
** parser_parse.c
*/

#include "my.h"
#include "separator.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>

static separator_t const *get_separator(parser_t *parser, char const *input)
{
    return parser_handle_separator(parser, input + parser->index);
}

static bool is_quoted(parser_t *parser, char const *input)
{
    if (!parser_get_quote(parser) && input[parser->index] == '"')
        parser_set_dblquote(parser, !parser_get_dblquote(parser));
    if (!parser_get_dblquote(parser) && input[parser->index] == '\'')
        parser_set_quote(parser, !parser_get_quote(parser));
    if (parser_get_quote(parser) || parser_get_dblquote(parser))
        return true;
    return false;
}

static int add_tokens(parser_t *parser, char *to_add)
{
    size_t tokens_len = my_len_word_array(parser->tokens);
    char **new = realloc(parser_get_tokens(parser),
        (tokens_len + 2) * sizeof(char *));

    new[tokens_len] = to_add;
    new[tokens_len + 1] = NULL;
    parser_set_tokens(parser, new);
    return 0;
}

static int handle_separator(parser_t *parser, char const *input,
    size_t current_len, separator_t *separator)
{
    char *tmp = NULL;

    if (current_len) {
        tmp = strndup(input + parser->index - current_len, current_len);
        if (!tmp)
            return 84;
        add_tokens(parser, tmp);
    }
    if (!separator)
        return 0;
    tmp = strdup(separator->separator);
    if (!tmp)
        return 84;
    add_tokens(parser, tmp);
    parser->index += strlen(separator->separator) - 1;
    return 0;
}

int parser_parse(parser_t *parser, char const *input)
{
    size_t current_len = 0;
    separator_t *separator = NULL;

    for (; input[parser->index]; parser->index++) {
        separator = NULL;
        if (!is_quoted(parser, input))
            separator = (void *)get_separator(parser, input);
        if (!parser_get_quote(parser) && !parser_get_dblquote(parser)
            && separator) {
            handle_separator(parser, input, current_len, separator);
            current_len = 0;
            continue;
        }
        current_len++;
    }
    handle_separator(parser, input, current_len, NULL);
    return 0;
}
