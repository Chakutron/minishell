/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:38:18 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 10:06:54 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export5(t_data *data, int index, int j)
{
	if (ft_strncmp(data->cmd[index], "PATH=", j + 1) == 0)
		update_path(data);
	if (data->no_equal)
		data->cmd[index][j] = '\0';
	addback_env(data, data->cmd[index]);
}

void	export4(t_data *data, int index, int e, int j)
{
	if (data->concat == 0)
	{
		free(data->new_env[e]);
		if (data->no_equal)
		{
			data->no_equal = 0;
			data->cmd[index][j] = '\0';
		}
		data->new_env[e] = ft_strdup2(data->cmd[index]);
	}
	else if (data->concat == 1)
	{
		if (data->new_env[e][j] == '\0')
		{
			data->new_env[e][j] = '=';
			data->new_env[e][j + 1] = '\0';
		}
		data->new_env[e] = ft_strjoin2(data->new_env[e],
				&data->cmd[index][j + 1]);
	}
}

int	export3(t_data *data, int index, int j)
{
	j = export2(data, index, 0, 0);
	data->no_equal = 0;
	if (data->cmd[index][j] == '\0')
	{
		data->no_equal = 1;
		data->cmd[index] = ft_strcat2(data->cmd[index], '=');
	}
	return (j);
}

int	export2(t_data *data, int index, int j, int i)
{
	while (data->cmd[index][j] != '=' && data->cmd[index][j])
		j++;
	data->concat = 0;
	if (data->cmd[index][j] == '=' && data->cmd[index][j - 1] == '+')
	{
		i = 0;
		j = 0;
		while (data->cmd[index][i])
		{
			if (data->cmd[index][i] != '+')
			{
				data->cmd[index][j] = data->cmd[index][i];
				j++;
			}
			i++;
		}
		data->cmd[index][j] = '\0';
		data->concat = 1;
		j = 0;
		while (data->cmd[index][j] != '=')
			j++;
	}
	return (j);
}

int	export(t_data *data, int index)
{
	int		j;

	if (export6(data, index))
		return (EXIT_SUCCESS);
	if (export7(data, index))
		return (EXIT_FAILURE);
	j = export3(data, index, 0);
	if (export8(data, index, j, 0))
		return (EXIT_SUCCESS);
	export5(data, index, j);
	return (EXIT_SUCCESS);
}
