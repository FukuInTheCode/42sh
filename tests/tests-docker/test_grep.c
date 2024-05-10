/*
** EPITECH PROJECT, 2023
** testing_grep.c
** File description:
** abc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
int exec_suite(char *buf, list_t *list, int *status);

Test(pipe, test_grep)
{
    cr_redirect_stdout();
    system("echo \"ls | grep Ma | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M | grep M\" | ./mysh ");
    cr_assert_stdout_eq_str("Makefile\n");
}

Test(pipe, test_folder)
{
    cr_redirect_stdout();
    system("echo \"ls | grep include | grep i | grep u | grep include\" | ./mysh");
    cr_assert_stdout_eq_str("include\n");
}

Test(pipe, test_with_exit)
{
    cr_redirect_stdout();
    system("echo \"exit | ls | grep src\" | ./mysh");
    cr_assert_stdout_eq_str("src\n");
}

Test(pipe, test_empty_pipe)
{
    cr_redirect_stderr();
    system("echo \" | \" | ./mysh");
    cr_assert_stderr_eq_str("Invalid null command.\n");
}

Test(pipe, classic_grep)
{
    cr_redirect_stdout();
    system("echo \"ls | grep include\" | ./mysh");
    cr_assert_stdout_eq_str("include\n");
}
