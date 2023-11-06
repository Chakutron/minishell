/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 14:10:04 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern pid_t	g_tsh_pid;

void	parser2(t_data *data, char **copyline)
{
	add_history(data->line);
	trimming(data, 0);
	if (!data->line_error)
	{
		*copyline = ft_strdup2(data->line);
		data->flag = 0;
		if (!working_cmd(data))
		{
			free(data->line);
			data->line = *copyline;
			data->flag = 1;
			working_cmd(data);
		}
		else
			free(*copyline);
	}
	else
		data->line_error = 0;
}

void	parser(t_data *data)
{
	char	*copyline;

	printf("\n\e[35m--- ToxicShell by Chaku & Trorioll TM 2023 ---\e[0m\n\n");
	while (1)
	{
		setup_terminal(data);
		g_tsh_pid = 0;
		data->line = readline(PROMPT);
		if (data->line == NULL)
			finishing(data, NULL);
		if (!only_space(data->line))
			parser2(data, &copyline);
		free(data->line);
	}
}
