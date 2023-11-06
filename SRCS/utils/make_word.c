/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:23:59 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 14:15:53 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*make_word(char	*str, int len)
{
	int		i;
	char	*word;

	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
