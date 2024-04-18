/*
** EPITECH PROJECT, 2024
** parser_to_command.c
** File description:
** parser_to_command.c
*/

#include "my.h"
#include "command.h"
#include "parser.h"
#include <string.h>
#include <stdio.h>


static bool token_is_empty(char const *s)
{
    if (!s)
        return true;
    for (size_t i = 0; s[i]; i++)
        if (s[i] != ' ' && s[i] != '\t')
            return false;
    return true;
}

static command_t *get_last(command_t *head)
{
    if (!head)
        return NULL;
    for (; command_get_next(head); head = command_get_next(head));
    return head;
}

static int handle_token(parser_t *parser, command_t **head)
{
    command_t *tmp = NULL;
    size_t i = 0;

    for (; separators[i].f; i++) {
        if (strcmp(parser->tokens[parser->index], separators[i].separator))
            continue;
        tmp = ((command_f_t *)separators[i].f)(parser, get_last(*head));
        break;
    }
    if (!separators[i].f)
        tmp = parser_command_command(parser);
    if (!tmp)
        return 84;
    if (!*head)
        *head = tmp;
    else
        command_add(*head, tmp);
    return 0;
}

static int set_waits(command_t *head)
{
    command_t *last = NULL;

    for (; head; head = command_get_next(head)) {
        if (command_get_type(head) == COMMAND)
            last = head;
        if (command_get_type(head) == END && last)
            command_set_wait(last, true);
    }
    if (last)
        command_set_wait(last, true);
    return 0;
}

command_t *parser_to_command(parser_t *parser)
{
    command_t *head = NULL;

    for (parser->index = 0; parser->tokens[parser->index]; parser->index++) {
        if (token_is_empty(parser->tokens[parser->index]))
            continue;
        if (handle_token(parser, &head) == 84) {
            command_destroy(head);
            return NULL;
        }
    }
    set_waits(head);
    return head;
}
