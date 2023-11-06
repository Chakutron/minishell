/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:44 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 13:57:17 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	finishing2(t_data *data, char *str)
{
	int		i;
	char	*tmp;

	if (str)
		tmp = ft_strdup2(str);
	else
		tmp = NULL;
	i = 0;
	while (i < 1024)
	{
		if (data->cmd[i])
			free(data->cmd[i]);
		i++;
	}
	close(data->original_in);
	close(data->original_out);
	restore_terminal(data);
	if (!tmp)
		exit(data->status);
	data->status = ft_atoi(tmp);
	free(tmp);
	exit(data->status);
}

void	finishing(t_data *data, char *str)
{
	int		i;

	if (data->line)
		free(data->line);
	rl_clear_history();
	i = 0;
	while (data->path[i])
	{
		free(data->path[i]);
		i++;
	}
	free(data->path);
	i = 0;
	while (data->new_env[i])
	{
		free(data->new_env[i]);
		i++;
	}
	free(data->new_env);
	free(data->file_in);
	free(data->delim);
	free(data->file_out);
	finishing2(data, str);
}
