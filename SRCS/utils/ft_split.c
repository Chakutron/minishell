/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:23:59 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 14:16:59 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_split2(t_data *data, char *str, char c)
{
	int	flag;

	flag = data->i;
	while (str[data->i] != c && str[data->i])
		data->i++;
	data->array[data->word] = make_word(&str[flag], data->i - flag);
	data->word++;
}

char	**ft_split(t_data *data, char *str, char c)
{
	data->array = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (data->array == NULL)
		return (NULL);
	data->i = 0;
	data->word = 0;
	while (str[data->i])
	{
		if (str[data->i] != c)
			ft_split2(data, str, c);
		if (str[data->i] == '\0')
			break ;
		data->i++;
	}
	data->array[data->word] = NULL;
	return (data->array);
}
