/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 15:42:49 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_dollar2(t_data *data, char *s1)
{
	data->i = data->j + 1;
	while (s1[data->i])
	{
		if (s1[data->i] >= 9 && s1[data->i] <= 13)
			break ;
		else if (s1[data->i] == ' ' || s1[data->i] == 39 || s1[data->i] == 34)
			break ;
		data->i++;
	}
	data->tmp = ft_strdup2(&s1[data->j + 1]);
	data->tmp[data->i - data->j - 1] = '\0';
	data->tmp2 = getenv2(data, data->tmp);
	if (!data->tmp2)
		data->tmp2 = ft_calloc(1, 1);
	data->s2 = ft_strjoin2(data->s2, data->tmp2);
	free(data->tmp);
	free(data->tmp2);
	data->j = data->i;
}

void	check_dollar3(t_data *data, char *s1)
{
	if (s1[data->j + 1] == '?')
	{
		data->tmp2 = ft_itoa(data->status);
		data->s2 = ft_strjoin2(data->s2, data->tmp2);
		free(data->tmp2);
		data->j = data->j + 2;
	}
	else if (s1[data->j + 1] == ' ' || s1[data->j + 1] == '\0')
	{
		data->s2 = ft_strcat2(data->s2, '$');
		data->j++;
	}
	else
		check_dollar2(data, s1);
}

char	*check_dollar(t_data *data, char *s1)
{
	data->s2 = ft_calloc(1, 1);
	data->j = 0;
	while (s1[data->j])
	{
		if (s1[data->j] == '$')
			check_dollar3(data, s1);
		else
		{
			data->s2 = ft_strcat2(data->s2, s1[data->j]);
			data->j++;
		}
	}
	if (data->s2[0] != '\0')
	{
		free(s1);
		return (data->s2);
	}
	free(data->s2);
	return (s1);
}
