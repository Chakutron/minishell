/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:02:51 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 15:32:53 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	len;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	len = nmemb * size;
	if ((len / size) != nmemb)
		return (NULL);
	tab = malloc(len);
	if (!tab)
		return (NULL);
	ft_bzero(tab, len);
	return (tab);
}
