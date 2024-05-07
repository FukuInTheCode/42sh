/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "my.h"
#include "env.h"

////////////////////////////////////////////////////////////
// int main(int argc, char **argv, char **envp)
//
// argc -> number of arguments
// argv -> array of arguments
// envp -> array of environment values at starting
//
// This function launches the init of the data, the shell loop
// and the free of the data at the end of the execution.
//
// RETURN VALUE : int that represent the status of the execution
// the program return 84 when an error occurs, and return the last
// return value of the last command executed if all works correctly.
////////////////////////////////////////////////////////////
int main(int argc, char **argv, char **envp)
{
    shell_t *shell = NULL;
    int code = 0;

    if (argc != 1 || !argv)
        return 84;
    shell = shell_create();
    shell_set_env(shell, env_copy(envp));
    if (shell_run(shell) == 84) {
        shell_destroy(shell);
        return 84;
    }
    code = shell_get_code(shell);
    shell_destroy(shell);
    return code;
}
