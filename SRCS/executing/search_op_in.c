/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:29 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 14:12:25 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	search_op_in(t_data *data)
{
	int		fd_file_in;
	int		ret;

	ret = 0;
	if (data->op_in == 1 || data->op_in == 4)
	{
		fd_file_in = open(data->file_in, O_RDONLY);
		if (fd_file_in == -1)
		{
			printf_error("ToxicShell: ");
			printf_error(data->file_in);
			printf_error(": no such file or directory (1)\n");
			return (EXIT_FAILURE);
		}
		dup2(fd_file_in, 0);
		search_op_out(data);
		close(fd_file_in);
	}
	else
		search_op_out(data);
	return (ret);
}
