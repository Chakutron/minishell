/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 15:44:41 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_operator(char *str)
{
	if (!str)
		return (1);
	else if (!strcmp(str, "<"))
		return (1);
	else if (!strcmp(str, "<<"))
		return (1);
	else if (!strcmp(str, "|"))
		return (1);
	else if (!strcmp(str, ">"))
		return (1);
	else if (!strcmp(str, ">>"))
		return (1);
	return (0);
}
