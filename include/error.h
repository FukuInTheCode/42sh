/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define ERROR_H


typedef int(*err_func_t)();

typedef struct error_s {
    char const *err;
    err_func_t f;
} myerror_t;

int error_put(myerror_t *);
