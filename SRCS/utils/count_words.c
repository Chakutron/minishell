/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:23:59 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 14:16:22 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_words(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && ((i == 0) || str[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}
