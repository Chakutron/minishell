/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:29:29 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 13:52:41 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern pid_t	g_tsh_pid;

void	father(t_data *data)
{
	waitpid(g_tsh_pid, &(data->status), 0);
	data->status = data->status >> 8;
	if (data->op_out == 3)
	{
		dup2(data->pipefd[0], 0);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
	}
	else if (data->op_out == 0)
	{
		dup2(data->original_in, 0);
		dup2(data->original_out, 1);
	}
}
