/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 15:40:52 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	add_cmd(t_data *data, char *token)
{
	int	i;

	i = 0;
	while (i < 1024 && data->cmd[i] && data->cmd[i][0] != '\0')
		i++;
	if (i > 1023)
		return (1);
	if (data->cmd[i])
		free(data->cmd[i]);
	data->cmd[i] = token;
	return (0);
}
