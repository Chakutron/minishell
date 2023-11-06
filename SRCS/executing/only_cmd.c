/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:29 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 10:20:08 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*only_cmd(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s);
	while (s[i - 1] != '/')
		i--;
	str = malloc(ft_strlen(&s[i]) + 1);
	j = 0;
	while (s[i + j])
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	free(s);
	return (str);
}
