##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Placeholder
##

NAME   = 42sh

CC	  = gcc

WFLAGS = -Wall -Wextra -Werror

LIBS = -lm -lc

CFLAGS = -I./include/ $(WFLAGS) $(LIBS)

SRC = src/main.c \
	src/error/error_put.c \
	src/parser/setter/parser_set_index.c \
	src/parser/setter/parser_set_quote.c \
	src/parser/setter/parser_set_dblquote.c \
	src/parser/setter/parser_set_tokens.c \
	src/parser/parser_command_right.c \
	src/parser/parser_command_left.c \
	src/parser/parser_to_command.c \
	src/parser/parser_command_double_right.c \
	src/parser/parser_command_command.c \
	src/parser/parser_handle_separator.c \
	src/parser/parser_command_other.c \
	src/parser/parser_command_open_subshell.c \
	src/parser/parser_command_or.c \
	src/parser/parser_command_double_left.c \
	src/parser/parser_command_and.c \
	src/parser/parser_command_close_subshell.c \
	src/parser/parser_command_pipe.c \
	src/parser/parser_command_end.c \
	src/parser/parser_create.c \
	src/parser/getter/parser_get_index.c \
	src/parser/getter/parser_get_tokens.c \
	src/parser/getter/parser_get_dblquote.c \
	src/parser/getter/parser_get_quote.c \
	src/parser/parser_parse.c \
	src/parser/parser_destroy.c \
	src/line_edition/arrow_react.c \
	src/line_edition/input_handling.c \
	src/line_edition/str_shift.c \
	src/line_edition/get_input.c \
	src/line_edition/set_canonical_mode.c \
	src/line_edition/extend_buffer.c \
	src/line_edition/set_noncanonical_mode.c \
	src/variables/get_variable.c \
	src/my/my_len_word_array.c \
	src/my/my_copy_word_array.c \
	src/my/my_cat_word_array.c \
	src/my/my_str_to_word_array.c \
	src/my/my_char_is_in_str.c \
	src/my/my_free_word_array.c \
	src/env/env_destroy.c \
	src/env/env_remove.c \
	src/env/env_get.c \
	src/env/env_copy.c \
	src/env/env_change.c \
	src/env/env_add.c \
	src/shell/setter/shell_set_in.c \
	src/shell/setter/shell_set_out.c \
	src/shell/setter/shell_set_exit.c \
	src/shell/setter/shell_set_cmds.c \
	src/shell/setter/shell_set_history_id.c \
	src/shell/setter/shell_set_env.c \
	src/shell/setter/shell_set_history.c \
	src/shell/setter/shell_set_code.c \
	src/shell/setter/shell_set_err.c \
	src/shell/shell_clean.c \
	src/shell/shell_init_variable.c \
	src/shell/shell_process_subshell.c \
	src/shell/shell_process_command.c \
	src/shell/shell_run_edition_mode.c \
	src/shell/shell_process_input.c \
	src/shell/shell_process_or.c \
	src/shell/shell_process_cmds_error.c \
	src/shell/shell_destroy.c \
	src/shell/shell_handle_prompt.c \
	src/shell/shell_process_and.c \
	src/shell/shell_process_commands.c \
	src/shell/shell_create.c \
	src/shell/shell_run.c \
	src/shell/getter/shell_get_code.c \
	src/shell/getter/shell_get_in.c \
	src/shell/getter/shell_get_history.c \
	src/shell/getter/shell_get_exit.c \
	src/shell/getter/shell_get_cmds.c \
	src/shell/getter/shell_get_err.c \
	src/shell/getter/shell_get_history_id.c \
	src/shell/getter/shell_get_env.c \
	src/shell/getter/shell_get_out.c \
	src/shell/shell_parse_input.c \
	src/command/setter/command_set_argc.c \
	src/command/setter/command_set_err.c \
	src/command/setter/command_set_prev.c \
	src/command/setter/command_set_pid.c \
	src/command/setter/command_set_type.c \
	src/command/setter/command_set_in.c \
	src/command/setter/command_set_wait.c \
	src/command/setter/command_set_argv.c \
	src/command/setter/command_set_out.c \
	src/command/setter/command_set_path.c \
	src/command/setter/command_set_status.c \
	src/command/setter/command_set_next.c \
	src/command/command_process_builtins.c \
	src/command/command_handle_null_error.c \
	src/command/command_handle_closes.c \
	src/command/command_handle_name_error.c \
	src/command/command_handle_divzero_error.c \
	src/command/command_handle_toomanyopen_error.c \
	src/command/command_handle_fork.c \
	src/command/command_handle_pipe.c \
	src/command/command_exec.c \
	src/command/command_handle_right_red.c \
	src/command/command_process_in.c \
	src/command/command_handle_dir_error.c \
	src/command/command_process_exec_error.c \
	src/command/command_copy.c \
	src/command/command_handle_perm_error.c \
	src/command/command_handle_badly_error.c \
	src/command/command_handle_left_red.c \
	src/command/command_destroy.c \
	src/command/command_handle_toomanyclose_error.c \
	src/command/command_handle_double_right_red.c \
	src/command/command_process_null_error.c \
	src/command/command_process_path.c \
	src/command/command_add.c \
	src/command/command_handle_segfault_error.c \
	src/command/command_handle_builtins.c \
	src/command/command_process_status.c \
	src/command/command_handle_arch_error.c \
	src/command/command_process_user_errors.c \
	src/command/command_process_err.c \
	src/command/command_wait.c \
	src/command/command_handle_longname_error.c \
	src/command/command_handle_brokenpipe_error.c \
	src/command/command_create.c \
	src/command/command_handle_output_error.c \
	src/command/command_handle_double_left_red.c \
	src/command/command_handle_opens.c \
	src/command/command_handle_input_error.c \
	src/command/command_handle_found_error.c \
	src/command/getter/command_get_out.c \
	src/command/getter/command_get_pid.c \
	src/command/getter/command_get_path.c \
	src/command/getter/command_get_type.c \
	src/command/getter/command_get_next.c \
	src/command/getter/command_get_in.c \
	src/command/getter/command_get_wait.c \
	src/command/getter/command_get_prev.c \
	src/command/getter/command_get_status.c \
	src/command/getter/command_get_err.c \
	src/command/getter/command_get_argv.c \
	src/command/getter/command_get_argc.c \
	src/command/command_process_out.c \
	src/command/command_process_status_error.c \
	src/command/command_handle_segfault_coredumped_error.c \
	src/command/command_handle_divzero_coredumped_error.c \
	src/command/command_handle_killed_error.c \
	src/command/command_handle_loop_error.c \
	src/autocompletion/set_command.c \
	src/autocompletion/find_lenght.c \
	src/autocompletion/tabulation_alone.c \
	src/autocompletion/autocomplete.c \
	src/autocompletion/display_command.c \
	src/autocompletion/search_command.c \
	src/separator/separator_cmp.c \
	src/builtin/glob/builtin_do_glob.c \
	src/builtin/pushd/builtin_do_pushd.c \
	src/builtin/cd/builtin_handle_cd_errors.c \
	src/builtin/cd/builtin_handle_cd_dir_error.c \
	src/builtin/cd/builtin_do_cd.c \
	src/builtin/cd/builtin_handle_cd_exist_error.c \
	src/builtin/cd/builtin_handle_cd_access_error.c \
	src/builtin/repeat/builtin_do_repeat.c \
	src/builtin/umask/builtin_do_umask.c \
	src/builtin/setenv/builtin_do_setenv.c \
	src/builtin/unalias/builtin_do_unalias.c \
	src/builtin/else/builtin_do_else.c \
	src/builtin/builtins/builtin_display_builtins.c \
	src/builtin/builtins/builtin_do_builtins.c \
	src/builtin/where/builtin_display_where.c \
	src/builtin/where/builtin_do_where.c \
	src/builtin/foreach/builtin_do_foreach.c \
	src/builtin/rehash/builtin_do_rehash.c \
	src/builtin/hup/builtin_do_hup.c \
	src/builtin/filetest/builtin_do_filetest.c \
	src/builtin/suspend/builtin_do_suspend.c \
	src/builtin/unlimit/builtin_do_unlimit.c \
	src/builtin/echo/builtin_do_echo.c \
	src/builtin/echotc/builtin_do_echotc.c \
	src/builtin/switch/builtin_do_switch.c \
	src/builtin/colon/builtin_do_colon.c \
	src/builtin/eval/builtin_do_eval.c \
	src/builtin/case/builtin_do_case.c \
	src/builtin/stop/builtin_do_stop.c \
	src/builtin/builtin_handle_varname_error.c \
	src/builtin/bindkey/builtin_do_bindkey.c \
	src/builtin/uncomplete/builtin_do_uncomplete.c \
	src/builtin/endif/builtin_do_endif.c \
	src/builtin/exec/builtin_do_exec.c \
	src/builtin/break/builtin_do_break.c \
	src/builtin/popd/builtin_do_popd.c \
	src/builtin/breaksw/builtin_do_breaksw.c \
	src/builtin/source/builtin_do_source.c \
	src/builtin/onintr/builtin_do_onintr.c \
	src/builtin/nohup/builtin_do_nohup.c \
	src/builtin/if/builtin_do_if.c \
	src/builtin/limit/builtin_do_limit.c \
	src/builtin/termname/builtin_do_termname.c \
	src/builtin/while/builtin_do_while.c \
	src/builtin/builtin_handle_varfirst_error.c \
	src/builtin/exit/builtin_do_exit.c \
	src/builtin/exit/builtin_handle_exit_badnum_error.c \
	src/builtin/exit/builtin_handle_exit_exprsyn_error.c \
	src/builtin/unsetenv/builtin_do_unsetenv.c \
	src/builtin/shift/builtin_do_shift.c \
	src/builtin/goto/builtin_do_goto.c \
	src/builtin/alias/builtin_do_alias.c \
	src/builtin/alloc/builtin_do_alloc.c \
	src/builtin/logout/builtin_do_logout.c \
	src/builtin/telltc/builtin_do_telltc.c \
	src/builtin/bg/builtin_do_bg.c \
	src/builtin/at/builtin_do_at.c \
	src/builtin/dirs/builtin_do_dirs.c \
	src/builtin/notify/builtin_do_notify.c \
	src/builtin/setty/builtin_do_setty.c \
	src/builtin/nice/builtin_do_nice.c \
	src/builtin/unset/builtin_do_unset.c \
	src/builtin/complete/builtin_do_complete.c \
	src/builtin/endsw/builtin_do_endsw.c \
	src/builtin/end/builtin_do_end.c \
	src/builtin/log/builtin_do_log.c \
	src/builtin/set/builtin_do_set.c \
	src/builtin/set/builtin_get_variables.c \
	src/builtin/set/linked_list_set/builtin_free_linked_list_set.c \
	src/builtin/set/linked_list_set/builtin_add_set_linked_list.c \
	src/builtin/set/linked_list_set/builtin_remove_set_linked_list.c \
	src/builtin/continue/builtin_do_continue.c \
	src/builtin/sched/builtin_do_sched.c \
	src/builtin/time/builtin_do_time.c \
	src/builtin/hashstat/builtin_do_hashstat.c \
	src/builtin/history/add_in_history.c \
	src/builtin/history/display_history.c \
	src/builtin/history/copy_history.c \
	src/builtin/history/buitin_do_history.c \
	src/builtin/history/remove_history.c \
	src/builtin/history/load_from_file.c \
	src/builtin/history/save_history.c \
	src/builtin/printenv/builtin_do_printenv.c \
	src/builtin/default/builtin_do_default.c \
	src/builtin/settc/builtin_do_settc.c \
	src/builtin/unhash/builtin_do_unhash.c \
	src/builtin/which/builtin_display_which.c \
	src/builtin/which/is_builtin.c \
	src/builtin/which/builtin_do_which.c \
	src/builtin/fg/builtin_do_fg.c \
	src/builtin/login/builtin_do_login.c \
	src/builtin/jobs/builtin_do_jobs.c \
	src/builtin/wait/builtin_do_wait.c \

OBJ	= $(SRC:src/%.c=obj/%.o)

RED = \033[1;31m

GREEN = \033[1;32m

BLUE = \033[1;34m

NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "$(BLUE)Compiling binary...$(NC)"
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

obj/%.o: src/%.c
	@echo -e "$(GREEN)Compiling $<...$(NC)"
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@if [ -d obj/ ]; then echo -e "$(RED)Cleaning objects.$(NC)"; fi
	@rm -rf obj

fclean: clean
	@if [ -e "$(NAME)" ]; then echo -e "$(RED)Cleaning binary.$(NC)"; fi
	@rm -f $(NAME)

tests_run:
	@echo -e "$(BLUE)Running tests...$(NC)"

d: debug

debug: CFLAGS += -g
debug: $(NAME)
	@valgrind --log-file=/tmp/valgrind-$(NAME) --track-fds=all \
		--leak-check=full --show-leak-kinds=all ./$(NAME)
	@cat /tmp/valgrind-$(NAME)

re: fclean all
