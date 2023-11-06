/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:29 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 13:53:37 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern pid_t	g_tsh_pid;

int	execute7(t_data *data)
{
	g_tsh_pid = fork();
	if (g_tsh_pid == -1)
	{
		printf_error("ToxicShell: fork error\n");
		return (data->status = EXIT_FAILURE);
	}
	else if (g_tsh_pid == 0)
	{
		if (data->op_out == 3)
		{
			dup2(data->pipefd[1], 1);
			close(data->pipefd[0]);
			close(data->pipefd[1]);
		}
		data->ret = search_op_in(data);
		data->status = data->ret;
		exit(data->ret);
	}
	else
		father(data);
	return (data->status);
}

void	execute6(t_data *data)
{
	int	i;

	i = 1;
	while (data->cmd[i])
	{
		unset(data, i);
		i++;
	}
}

int	execute5(t_data *data)
{
	int	i;

	if (data->cmd[1] != NULL)
	{
		i = 1;
		while (data->cmd[i])
		{
			if (export(data, i) == EXIT_FAILURE)
				break ;
			i++;
		}
		return (1);
	}
	return (0);
}
