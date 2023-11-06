/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 15:43:54 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_cmd(t_data *data)
{
	int	i;
	int	last;

	i = 0;
	while (i < 1024 && data->cmd[i])
	{
		last = ft_strlen(data->cmd[i]) - 1;
		if (last)
		{
			if (data->cmd[i][0] == 39 && data->cmd[i][last] == 39)
				data->cmd[i] = clear_cmd(data->cmd[i]);
			else if (data->cmd[i][0] == 34 && data->cmd[i][last] == 34)
			{
				data->cmd[i] = clear_cmd(data->cmd[i]);
				data->cmd[i] = check_dollar(data, data->cmd[i]);
			}
			else
				data->cmd[i] = check_dollar(data, data->cmd[i]);
		}
		i++;
	}
}
