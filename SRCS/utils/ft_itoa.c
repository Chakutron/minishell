/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:25:17 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 15:28:09 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = nbr_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = -1;
		n *= -1;
	}
	len--;
	while (len >= 0)
	{
		str[len] = 48 + (n % 10);
		len--;
		n /= 10;
	}
	return (str);
}
