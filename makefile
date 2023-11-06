# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 15:15:55 by mchiboub          #+#    #+#              #
#    Updated: 2023/11/06 17:16:28 by mchiboub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = 	SRCS/builtin/addback_env.c		\
		SRCS/core/finishing.c			\
		SRCS/parsing/add_cmd.c			\
		SRCS/utils/ft_atoi.c			\
		SRCS/builtin/change_dir.c		\
		SRCS/core/get_path.c			\
		SRCS/parsing/check_dollar.c		\
		SRCS/utils/ft_bzero.c			\
		SRCS/builtin/delete_env.c		\
		SRCS/core/init.c				\
		SRCS/parsing/clear_cmd.c		\
		SRCS/utils/ft_calloc.c			\
		SRCS/builtin/echo.c				\
		SRCS/core/printf_error.c		\
		SRCS/parsing/is_operator.c		\
		SRCS/utils/ft_is_num.c			\
		SRCS/builtin/export.c			\
		SRCS/core/update_path.c			\
		SRCS/parsing/next_token.c		\
		SRCS/utils/ft_itoa.c			\
		SRCS/builtin/export_bis.c		\
		SRCS/executing/command.c		\
		SRCS/parsing/only_space.c		\
		SRCS/utils/ft_split.c			\
		SRCS/builtin/getenv2.c			\
		SRCS/executing/command_bis.c	\
		SRCS/parsing/parser.c			\
		SRCS/utils/ft_strcat2.c			\
		SRCS/builtin/n_param.c			\
		SRCS/executing/delim_op.c		\
		SRCS/parsing/trimming.c			\
		SRCS/utils/ft_strchr2.c			\
		SRCS/builtin/print_env.c		\
		SRCS/executing/execute.c		\
		SRCS/parsing/trimming_bis.c		\
		SRCS/utils/ft_strcmp.c			\
		SRCS/core/create_file.c			\
		SRCS/builtin/pwd.c				\
		SRCS/executing/execute_bis.c	\
		SRCS/parsing/trimming_ter.c		\
		SRCS/utils/ft_strcpy2.c			\
		SRCS/builtin/sort_export.c		\
		SRCS/executing/executor.c		\
		SRCS/parsing/working_cmd.c		\
		SRCS/utils/ft_strdup2.c			\
		SRCS/builtin/str_no_equal.c		\
		SRCS/executing/father.c			\
		SRCS/parsing/working_cmd_bis.c	\
		SRCS/utils/ft_strjoin2.c		\
		SRCS/builtin/unset.c			\
		SRCS/executing/init_pipes.c		\
		SRCS/signals/handle_int.c		\
		SRCS/utils/ft_strlen.c			\
		SRCS/builtin/valid_export.c		\
		SRCS/executing/only_cmd.c		\
		SRCS/signals/handle_quit.c		\
		SRCS/utils/ft_strncmp.c			\
		SRCS/core/clean_array.c			\
		SRCS/executing/search_op_in.c	\
		SRCS/signals/restore_terminal.c	\
		SRCS/utils/make_word.c			\
		SRCS/core/clean_cmd.c			\
		SRCS/executing/search_op_out.c	\
		SRCS/signals/setup_terminal.c	\
		SRCS/utils/nbr_len.c			\
		SRCS/core/clear_variables.c		\
		SRCS/minishell.c				\
		SRCS/utils/count_words.c

OBJS = ${SRCS:.c=.o}

GREEN = \e[0;32m
YELLOW = \e[0;33m
NC = \e[0m

all: ${NAME}

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -lreadline
		@echo -n "${YELLOW}*${NC}"

${NAME}: compiling ${OBJS}
		@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lreadline
		@echo "]\n✅ ${GREEN}Done!${NC}"

compiling:
		@echo -n "☢️  Generating ${GREEN}${NAME}${NC} executable: ["

clean:
		@echo "❌ Deleting object files..\n"
		@rm -f ${OBJS}

fclean: clean
		@echo "❌ Deleting executable files..\n"
		@rm -f ${NAME}

re: fclean all
