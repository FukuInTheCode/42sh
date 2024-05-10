/*
** EPITECH PROJECT, 2024
** minishell2-m
** File description:
** test_command_list.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(command, verif_put_in_function)
{
    command_t **com_list = com_list_c("ls > coucou | grep M");
    //print_com_list(com_list);
    cr_redirect_stdout();
    print_com_list(com_list);
    cr_assert_stdout_eq_str("ls \n>\n coucou \n|\n grep M\n");
}

Test(command, verif_double_redir_right)
{
    command_t **com_list = com_list_c("ls >> coucou | grep M");
    //print_com_list(com_list);
    cr_redirect_stdout();
    print_com_list(com_list);
    cr_assert_stdout_eq_str("ls \nr\n coucou \n|\n grep M\n");
}

Test(command, verif_double_redir_left)
{
    command_t **com_list = com_list_c("ls << coucou | grep M");
    //print_com_list(com_list);
    cr_redirect_stdout();
    print_com_list(com_list);
    cr_assert_stdout_eq_str("ls \nl\n coucou \n|\n grep M\n");
}
