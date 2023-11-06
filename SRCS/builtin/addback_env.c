/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:38:18 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 10:03:22 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	addback_env(t_data *data, char *new_env)
{
	int		i;
	char	**new_env_table;

	i = 0;
	while (data->new_env[i])
		i++;
	new_env_table = malloc(sizeof(char *) * (i + 2));
	if (!new_env_table)
		return ;
	i = 0;
	while (data->new_env[i])
	{
		new_env_table[i] = data->new_env[i];
		i++;
	}
	new_env_table[i] = ft_strdup2(new_env);
	new_env_table[i + 1] = 0;
	free(data->new_env);
	data->new_env = new_env_table;
}
