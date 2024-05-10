/*
** EPITECH PROJECT, 2023
** testing_semicolon.c
** File description:
** abc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(semicolon, test_ls)
{
    cr_redirect_stdout();
    system("echo \"cd include/ ; ls -l | wc -l\" | ./mysh");
    cr_assert_stdout_eq_str("2\n");
}
