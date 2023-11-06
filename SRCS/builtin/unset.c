/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:22:14 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 10:10:58 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset(t_data *data, int index)
{
	int		e;
	char	*tmp_cmd;
	char	*tmp_env;

	tmp_cmd = ft_strdup2(data->cmd[index]);
	tmp_cmd = ft_strcat2(tmp_cmd, '=');
	e = 0;
	while (data->new_env[e])
	{
		tmp_env = ft_strdup2(data->new_env[e]);
		if (!ft_strchr2(tmp_env, '='))
			tmp_env = ft_strcat2(tmp_env, '=');
		if (ft_strncmp(tmp_cmd, tmp_env, ft_strlen(tmp_cmd)) == 0)
		{
			delete_env(data, e);
			update_path(data);
			free(tmp_env);
			break ;
		}
		free(tmp_env);
		e++;
	}
	free(tmp_cmd);
}
