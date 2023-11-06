/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:31:39 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/06 16:31:42 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_file(char *filename, int flag)
{
	int	fd;

	if (flag == 1)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close (fd);
	}
	else if (flag == 2)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		close (fd);
	}
}
