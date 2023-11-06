/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:02:51 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 15:36:06 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strcat2(char *s, char c)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = malloc(len + 2);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}
