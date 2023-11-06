/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:29 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 09:57:16 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_array(t_data *data)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (data->cmd[i] && data->cmd[i][0] == '\0')
		{
			free(data->cmd[i]);
			data->cmd[i] = NULL;
			break ;
		}
		i++;
	}
}
