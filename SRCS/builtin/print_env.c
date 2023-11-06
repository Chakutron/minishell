/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 10:16:52 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env(t_data *data, char *str)
{
	int		i;
	char	*tmp;

	if (str && ft_strlen(str))
	{
		tmp = getenv2(data, str);
		printf("%s=%s\n", str, tmp);
		free(tmp);
	}
	else
	{
		i = 0;
		while (data->new_env[i])
		{
			printf("%s\n", data->new_env[i]);
			i++;
		}
	}
}
