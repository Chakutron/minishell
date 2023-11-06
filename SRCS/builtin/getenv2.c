/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 10:14:22 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*getenv2(t_data *data, char *s)
{
	char	*envus;
	char	*str;
	int		i;
	int		len;

	str = ft_strdup2(s);
	str = ft_strcat2(str, '=');
	i = 0;
	while (data->new_env[i])
	{
		if (ft_strncmp(str, data->new_env[i], ft_strlen(str)) == 0)
		{
			len = ft_strlen(&(data->new_env[i][ft_strlen(str)]));
			envus = ft_calloc(1, len + 1);
			ft_strcpy2(&(data->new_env[i][ft_strlen(str)]), envus);
			free(str);
			return (envus);
		}
		i++;
	}
	free(str);
	return (NULL);
}
