/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 10:17:36 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo(t_data *data)
{
	int	n;
	int	i;

	n = 1;
	i = 1;
	while (data->cmd[i])
	{
		if (n_param(data->cmd[i]))
			n = 0;
		else
			break ;
		i++;
	}
	while (data->cmd[i])
	{
		printf("%s", data->cmd[i]);
		i++;
		if (data->cmd[i])
			printf(" ");
	}
	if (n)
		printf("\n");
}
