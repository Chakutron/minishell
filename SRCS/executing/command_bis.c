/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:29 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 22:26:38 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	command8(t_data *data)
{
	data->pathway = ft_strdup2(data->cmd[0]);
	data->tmp = getenv2(data, "PWD");
	data->tmp = ft_strcat2(data->tmp, '/');
	data->tmp2 = ft_strjoin2(data->tmp, data->pathway);
	free(data->pathway);
	free(data->cmd[1023]);
	data->cmd[1023] = ft_strdup2("PATH+=:");
	data->cmd[1023] = ft_strjoin2(data->cmd[1023], data->tmp2);
	free(data->tmp2);
	export(data, 1023);
	data->tmp = only_cmd(data->cmd[0]);
	data->cmd[0] = ft_strdup2("./");
	data->cmd[0] = ft_strjoin2(data->cmd[0], data->tmp);
	free(data->tmp);
	return (command5(data));
}

int	command6(t_data *data)
{
	int	ret;

	if (data->cmd[0][0] == '/')
	{
		data->pathway = ft_strdup2(data->cmd[0]);
		data->cmd[0] = only_cmd(data->cmd[0]);
		if (access(data->pathway, X_OK) == 0)
		{
			ret = execve(data->pathway, data->cmd, data->new_env);
			return (ret);
		}
		printf_error("ToxicShell: ");
		printf_error(data->pathway);
		printf_error(": No such file or directory\n");
		free(data->pathway);
		exit(127);
	}
	else
		return (command8(data));
}

void	command4(t_data *data)
{
	if (data->path[0])
	{
		printf_error("ToxicShell: command not found: ");
		printf_error(data->cmd[0]);
		printf_error("\n");
	}
	else
	{
		printf_error("ToxicShell: ");
		printf_error(data->cmd[0]);
		printf_error(": No such file or directory\n");
	}
	exit(127);
}
