/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_op_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:29 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 14:11:29 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	search_op_out2(t_data *data)
{
	printf_error("ToxicShell: ");
	printf_error(data->file_out);
	printf_error(": no such file or directory (2)\n");
}

int	search_op_out4(t_data *data, int fd_file_out)
{
	fd_file_out = open(data->file_out, O_WRONLY | O_CREAT
			| O_APPEND, 0644);
	if (fd_file_out == -1)
	{
		search_op_out2(data);
		return (1);
	}
	dup2(fd_file_out, 1);
	data->ret = command(data);
	close(fd_file_out);
	return (0);
}

int	search_op_out3(t_data *data, int fd_file_out)
{
	fd_file_out = open(data->file_out, O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (fd_file_out == -1)
	{
		search_op_out2(data);
		return (1);
	}
	dup2(fd_file_out, 1);
	data->ret = command(data);
	close(fd_file_out);
	return (0);
}

int	search_op_out(t_data *data)
{
	data->ret = 0;
	if (data->op_out == 1)
	{
		if (search_op_out3(data, 0))
			return (EXIT_FAILURE);
	}
	else if (data->op_out == 2)
	{
		if (search_op_out4(data, 0))
			return (EXIT_FAILURE);
	}
	else
		data->ret = command(data);
	return (data->ret);
}
