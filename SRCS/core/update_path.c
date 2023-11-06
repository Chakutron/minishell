/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:38:18 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 10:04:13 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->path[i])
	{
		free(data->path[i]);
		i++;
	}
	free(data->path);
	get_path(data);
}
