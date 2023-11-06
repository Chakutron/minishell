/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delim_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:29 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 13:51:32 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern pid_t	g_tsh_pid;

void	delim_op2(t_data *data)
{
	while (1)
	{
		data->tmp2 = readline("> ");
		if (data->tmp2 == NULL)
		{
			printf_error("ToxicShell: warning: document delimited with");
			printf_error("end-of-file (wanted '");
			printf_error(data->delim);
			printf_error("')\n");
			break ;
		}
		if (ft_strcmp(data->tmp2, data->delim) == 0)
		{
			data->tmp2 = ft_strcat2(data->tmp2, '\n');
			free(data->tmp2);
			break ;
		}
		else
		{
			data->tmp2 = ft_strcat2(data->tmp2, '\n');
			data->tmp = ft_strjoin2(data->tmp, data->tmp2);
			free(data->tmp2);
		}
	}
}

int	delim_op(t_data *data)
{
	int		fd_file_in;

	data->tmp = malloc(1);
	data->tmp[0] = '\0';
	delim_op2(data);
	data->op_in = 4;
	free(data->file_in);
	data->file_in = ft_strdup2(".ToxicShell_Temporal_File_Delim.tmp");
	fd_file_in = open(data->file_in, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd_file_in, data->tmp, ft_strlen(data->tmp));
	close(fd_file_in);
	free(data->tmp);
	if (!data->cmd[0])
	{
		data->status = 0;
		return (-42);
	}
	return (EXIT_SUCCESS);
}
