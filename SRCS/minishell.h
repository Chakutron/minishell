/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:11:36 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 16:05:49 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>

# define PROMPT "\001\e[32m\002<Toxic\001\e[33m\002Shell☠️> \001\e[0m\002"

typedef struct s_data
{
	char			**new_env;
	char			**new_env2;
	char			**path;
	char			*pathway;
	char			*cmd[1024];
	char			*line;
	int				line_error;
	char			dir[1024];
	int				original_in;
	int				original_out;
	int				pipefd[2];
	pid_t			child_delim;
	int				op_in;
	int				old_in;
	char			*file_in;
	char			*delim;
	int				op_out;
	int				old_out;
	int				tmp_file_in;
	int				tmp_file_out;
	char			*file_out;
	int				status;
	int				flag;
	int				inside;
	int				space;
	struct termios	original_attributes;
	char			**array;
	int				word;
	int				concat;
	int				no_equal;
	int				i;
	int				j;
	char			*tmp;
	char			*tmp2;
	char			*s1;
	char			*s2;
	int				ret;
	int				exec;
}					t_data;

int		ft_atoi(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *c);
char	*ft_strcat2(char *s, char c);
char	*ft_strdup2(char *s);
void	ft_strcpy2(char *s1, char *s2);
int		ft_strchr2(char *str, char c);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strcmp(char *s1, char const *s2);
int		ft_strncmp(char *s1, char const *s2, int n);
char	**ft_split(t_data *data, char *str, char c);
char	*ft_itoa(int n);

void	init(t_data *data, char *env[]);
void	get_path(t_data *data);
void	parser(t_data *data);
void	trimming(t_data *data, int echo);
void	trimming2(t_data *data);
void	trimming3(t_data *data);
void	trimming4(t_data *data);
void	trimming5(t_data *data);
void	trimming6(t_data *data);
void	trimming7(t_data *data);
void	trimming8(t_data *data, int echo);
void	trimming9(t_data *data, int echo);
void	trimming10(t_data *data);
void	trimming11(t_data *data);
void	trimming12(t_data *data, int echo);
int		working_cmd(t_data *data);
int		working_cmd2(t_data *data, char **token);
int		working_cmd3(t_data *data, char **token);
int		working_cmd4(t_data *data, char **token);
int		working_cmd5(t_data *data, char **token);
int		working_cmd6(t_data *data, char **token, int *pipe, int *cmd);
int		working_cmd7(t_data *data, char **token, int *pipe, int *cmd);
int		working_cmd8(t_data *data, int *pipe);
int		working_cmd9(t_data *data, char **token, int *pipe, int *cmd);
char	*next_token(t_data *data);
int		is_operator(char *str);
int		add_cmd(t_data *data, char *token);
void	executor(t_data *data);
void	get_path(t_data *data);
int		init_pipes(t_data *data);
int		execute(t_data *data);
void	execute2(void);
int		execute3(t_data *data);
int		execute4(t_data *data, int i, int num);
int		execute5(t_data *data);
void	execute6(t_data *data);
int		execute7(t_data *data);
int		execute8(t_data *data);
int		search_op_in(t_data *data);
int		search_op_out(t_data *data);
int		command(t_data *data);
void	command4(t_data *data);
int		command5(t_data *data);
int		command6(t_data *data);
void	clean_array(t_data *data);
void	clear_variables(t_data *data);
void	finishing(t_data *data, char *str);
void	setup_terminal(t_data *data);
void	restore_terminal(t_data *data);
void	create_file(char *filename, int flag);

char	*getenv2(t_data *data, char *s);
int		change_dir(t_data *data, char *dir);
void	print_env(t_data *data, char *str);
void	echo(t_data *data);
void	pwd(t_data *data);
int		export(t_data *data, int index);
int		export2(t_data *data, int index, int j, int i);
int		export3(t_data *data, int index, int j);
void	export4(t_data *data, int index, int e, int j);
void	export5(t_data *data, int index, int j);
int		export6(t_data *data, int index);
int		export7(t_data *data, int index);
int		export8(t_data *data, int index, int j, int e);

void	unset(t_data *data, int index);
void	update_path(t_data *data);
char	*clear_cmd(char *s1);
char	*check_dollar(t_data *data, char *s1);
char	*make_word(char *str, int len);
int		count_words(char *str, char c);
void	str_no_equal(char *str);
int		only_space(char *str);
void	handle_int(int sig);
void	handle_quit(int sig);
void	delete_env(t_data*data, int del);
int		nbr_len(int n);
void	addback_env(t_data *data, char *new_env);
int		valid_export(char c);
void	sort_export(t_data *data);
int		n_param(char *str);
void	ft_bzero(void *s, size_t n);
void	clean_cmd(t_data *data);
void	father(t_data *data);
int		delim_op(t_data *data);
int		ft_is_num(char *str);
char	*only_cmd(char *s);
void	printf_error(char *str);

#endif
