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

int	execute4(t_data *data, int i, int num)
{
	if (i > 2)
	{
		printf_error("exit\nToxicShell: exit: too many arguments\n");
		return (data->status = 1);
	}
	else if (num)
	{
		printf_error("exit\nToxicShell: exit: ");
		printf_error(data->cmd[num]);
		printf_error(": numeric argument required\n");
		return (data->status = 2);
	}
	else
	{
		printf_error("exit\n");
		finishing(data, data->cmd[1]);
	}
	return (0);
}

int	execute3(t_data *data)
{
	int	i;
	int	num;

	i = 1;
	num = 0;
	while (data->cmd[i])
	{
		if (!ft_is_num(data->cmd[i]) && !num)
			num = i;
		i++;
	}
	return (execute4(data, i, num));
}

void	execute2(void)
{
	printf_error("\nToxicShell: command '' not ");
	printf_error("found but can be installed with:\n\n");
	printf_error("apt install mailutils-mh  # version 1:3.7-2.1, or\n");
	printf_error("apt install meshio-tools  # version 4.0.4-1\n");
	printf_error("apt install mmh           # version 0.4-2\n");
	printf_error("apt install nmh           # version 1.7.1-6\n");
	printf_error("apt install termtris      # version 1.3-1\n");
	printf_error("\nAsk your administrator to install one of them.\n\n");
}

int	execute8(t_data *data)
{
	if (ft_strcmp(data->cmd[0], "..") == 0)
		return (printf_error("ToxicShell: ..: command not found\n"), 127);
	else if (ft_strcmp(data->cmd[0], "cd") == 0)
		return (data->status = change_dir(data, data->cmd[1]));
	else if (ft_strcmp(data->cmd[0], "exit") == 0)
	{
		data->i = execute3(data);
		if (data->i)
			return (data->status = data->i);
	}
	else if (ft_strcmp(data->cmd[0], "export") == 0)
	{
		data->i = execute5(data);
		if (data->i)
			return (data->status = EXIT_SUCCESS);
	}
	else if (ft_strcmp(data->cmd[0], "unset") == 0)
	{
		execute6(data);
		return (data->status = EXIT_SUCCESS);
	}
	data->exec = 0;
	return (0);
}

int	execute(t_data *data)
{
	data->ret = 0;
	init_pipes(data);
	if (!data->cmd[0])
		(void)data->cmd[0];
	else
	{
		if (data->cmd[0][0] == '\0')
		{
			execute2();
			return (data->status = 127);
		}
		data->exec = 1;
		data->status = execute8(data);
		if (data->exec)
			return (data->status);
	}
	if (data->op_in == 2)
	{
		if (delim_op(data) == -42)
			return (data->status);
	}
	execute7(data);
	return (data->status);
}
