/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 15:41:52 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*clear_cmd(char	*s1)
{
	int		i;
	int		len;
	char	*s2;

	i = 0;
	len = ft_strlen(s1) - 2;
	s2 = malloc(len + 1);
	if (!s2)
		return (s1);
	while (i < len)
	{
		s2[i] = s1[i + 1];
		i++;
	}
	s2[i] = '\0';
	free(s1);
	return (s2);
}
