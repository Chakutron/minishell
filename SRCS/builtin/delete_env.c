/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:22:14 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 15:47:06 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delete_env(t_data *data, int del)
{
	int		e;
	int		i;
	char	**new_env_table;

	e = 0;
	while (data->new_env[e])
		e++;
	new_env_table = malloc(sizeof(char *) * e);
	if (!new_env_table)
		return ;
	e = 0;
	i = 0;
	while (data->new_env[e])
	{
		if (e == del)
		{
			i = 1;
			free(data->new_env[e]);
			data->new_env[e] = NULL;
		}
		new_env_table[e] = data->new_env[e + i];
		e++;
	}
	free(data->new_env);
	data->new_env = new_env_table;
}
