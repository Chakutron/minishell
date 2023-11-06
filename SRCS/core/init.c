/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:44 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 13:55:58 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init2(t_data *data, char *env[], int i)
{
	while (env[i])
		i++;
	data->new_env = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (env[i])
	{
		data->new_env[i] = ft_strdup2(env[i]);
		i++;
	}
	i = 0;
	while (i < 1024)
	{
		data->cmd[i] = ft_calloc(1, 1);
		i++;
	}
	get_path(data);
	data->original_in = dup(0);
	data->original_out = dup(1);
	data->file_in = ft_calloc(1, 1);
	data->delim = ft_calloc(1, 1);
	data->file_out = ft_calloc(1, 1);
}

void	init(t_data *data, char *env[])
{
	char	*str;
	char	*tmp;

	init2(data, env, 0);
	data->line_error = 0;
	data->op_in = 0;
	data->old_in = 0;
	data->op_out = 0;
	data->old_out = 0;
	data->status = 0;
	str = getenv2(data, "SHLVL");
	tmp = ft_itoa(ft_atoi(str) + 1);
	free(str);
	str = ft_strdup2("SHLVL=");
	free(data->cmd[42]);
	data->cmd[42] = ft_strjoin2(str, tmp);
	free(tmp);
	export(data, 42);
	free(data->cmd[42]);
	data->cmd[42] = ft_strdup2("_");
	unset(data, 42);
	free(data->cmd[42]);
	data->cmd[42] = ft_calloc(1, 1);
}
