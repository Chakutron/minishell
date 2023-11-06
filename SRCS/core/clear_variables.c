/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:44 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 13:56:41 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clear_variables(t_data *data)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (data->cmd[i])
		{
			free(data->cmd[i]);
			data->cmd[i] = ft_calloc(1, 1);
		}
		i++;
	}
	data->op_in = 0;
	free(data->file_in);
	data->file_in = ft_calloc(1, 1);
	free(data->delim);
	data->delim = ft_calloc(1, 1);
	data->op_out = 0;
	free(data->file_out);
	data->file_out = ft_calloc(1, 1);
}
