/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:29 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 22:36:50 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	command7(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	while (data->path[i])
	{
		data->pathway = ft_strcat2(data->path[i], 47);
		data->pathway = ft_strjoin2(data->pathway, data->cmd[0]);
		if (access(data->pathway, X_OK) == 0)
		{
			ret = execve(data->pathway, data->cmd, data->new_env);
			return (ret);
		}
		free(data->pathway);
		i++;
	}
	command4(data);
	return (data->status);
}

void	command3(t_data *data)
{
	char	*tmp;

	tmp = data->cmd[0];
	data->cmd[0] = ft_strdup2(&(data->cmd[0][2]));
	free(tmp);
	tmp = getenv2(data, "PWD");
	free(data->cmd[1023]);
	data->cmd[1023] = ft_strdup2("PATH+=:");
	data->cmd[1023] = ft_strjoin2(data->cmd[1023], tmp);
	free(tmp);
	export(data, 1023);
	free(data->cmd[1023]);
	data->cmd[1023] = ft_calloc(1, 1);
}

int	command5(t_data *data)
{
	int	i;
	int	ret;

	command3(data);
	i = 0;
	while (data->path[i])
	{
		data->pathway = ft_strcat2(data->path[i], 47);
		data->pathway = ft_strjoin2(data->pathway, data->cmd[0]);
		if (access(data->pathway, X_OK) == 0)
		{
			ret = execve(data->pathway, data->cmd, data->new_env);
			return (ret);
		}
		free(data->pathway);
		i++;
	}
	printf_error("ToxicShell: command not found: ");
	printf_error(data->cmd[0]);
	printf_error("\n");
	exit(127);
}

int	command2(t_data *data)
{
	if (ft_strcmp(data->cmd[0], "env") == 0)
	{
		print_env(data, data->cmd[1]);
		return (EXIT_SUCCESS);
	}
	else if (ft_strcmp(data->cmd[0], "export") == 0)
	{
		if (data->cmd[1] == NULL)
			export(data, 1);
		return (EXIT_SUCCESS);
	}
	else if (ft_strcmp(data->cmd[0], "echo") == 0)
	{
		echo(data);
		return (EXIT_SUCCESS);
	}
	else if (ft_strcmp(data->cmd[0], "pwd") == 0)
	{
		pwd(data);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	command(t_data *data)
{
	int		ret;

	if (command2(data) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (data->cmd[0][0] == '.' && data->cmd[0][1] == 47)
		ret = command5(data);
	else if (ft_strchr2(data->cmd[0], 47))
		ret = command6(data);
	else
		ret = command7(data);
	return (ret);
}
