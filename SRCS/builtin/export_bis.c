/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:38:18 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 10:06:54 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	export8(t_data *data, int index, int j, int e)
{
	char	*tmp;

	while (data->new_env[e])
	{
		tmp = ft_strdup2(data->new_env[e]);
		if (!ft_strchr2(tmp, '='))
			tmp = ft_strcat2(tmp, '=');
		if (ft_strncmp(data->cmd[index], tmp, j + 1) == 0)
		{
			export4(data, index, e, j);
			free(tmp);
			if (ft_strncmp(data->cmd[index], "PATH=", j + 1) == 0)
				update_path(data);
			return (1);
		}
		free(tmp);
		e++;
	}
	return (0);
}

int	export7(t_data *data, int index)
{
	if (!valid_export(data->cmd[index][0]))
	{
		printf_error("ToxicShell: export: `");
		printf_error(data->cmd[index]);
		printf_error("': not a valid identifier\n");
		return (1);
	}
	return (0);
}

int	export6(t_data *data, int index)
{
	if (data->cmd[index] == NULL)
	{
		sort_export(data);
		return (1);
	}
	return (0);
}
