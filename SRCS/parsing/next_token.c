/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/10/14 16:03:08 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	next_token3(t_data *data, int i, char **str)
{
	*str = ft_strcat2(*str, data->line[i]);
	i++;
	while (data->line[i] != 39)
	{
		*str = ft_strcat2(*str, data->line[i]);
		i++;
	}
	*str = ft_strcat2(*str, data->line[i]);
	i++;
	return (i);
}

int	next_token2(t_data *data, int i, char **str)
{
	*str = ft_strcat2(*str, data->line[i]);
	i++;
	while (data->line[i] != 34)
	{
		*str = ft_strcat2(*str, data->line[i]);
		i++;
	}
	*str = ft_strcat2(*str, data->line[i]);
	i++;
	return (i);
}

int	next_token4(t_data *data, int i, char **str)
{
	while (data->line[i] != ' ' && data->line[i] != '\0')
	{
		if (data->line[i] == 34)
		{
			if (*str[0] != '\0')
				break ;
			i = next_token2(data, i, str);
			break ;
		}
		else if (data->line[i] == 39)
		{
			if (*str[0] != '\0')
				break ;
			i = next_token3(data, i, str);
			break ;
		}
		else
		{
			*str = ft_strcat2(*str, data->line[i]);
			i++;
		}
	}
	return (i);
}

char	*next_token(t_data *data)
{
	int		i;
	char	*str;
	char	*newline;

	if (data->line[0] == '\0')
		return (NULL);
	str = ft_calloc(1, 1);
	i = 0;
	while (data->line[i] == ' ')
		i++;
	i = next_token4(data, i, &str);
	newline = ft_strdup2(&(data->line[i]));
	free (data->line);
	data->line = newline;
	return (str);
}
