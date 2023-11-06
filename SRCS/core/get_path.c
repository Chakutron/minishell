/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:44 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 13:57:57 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_path(t_data *data)
{
	char	*path;

	path = getenv2(data, "PATH");
	if (!path)
		data->path = ft_calloc(sizeof(char *), 1);
	else
		data->path = ft_split(data, path, ':');
	free(path);
}
