/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/10/14 16:03:08 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	working_cmd8(t_data *data, int *pipe)
{
	if (*pipe)
	{
		printf_error("ToxicShell: syntax error: pipe error\n");
		clear_variables(data);
		return (1);
	}
	if (data->flag)
		executor(data);
	clear_variables(data);
	data->old_in = 0;
	data->old_out = 0;
	unlink(".ToxicShell_Temporal_File_Delim.tmp");
	return (0);
}

int	working_cmd7(t_data *data, char **token, int *pipe, int *cmd)
{
	if (*pipe)
		*pipe = 0;
	*cmd = 1;
	if (add_cmd(data, *token))
	{
		printf_error("ToxicShell: commmand stack overflow\n");
		clear_variables(data);
		return (1);
	}
	return (0);
}

int	working_cmd6(t_data *data, char **token, int *pipe, int *cmd)
{
	free(*token);
	if (!*cmd)
	{
		printf_error("ToxicShell: syntax error: pipe error\n");
		clear_variables(data);
		return (1);
	}
	else
	{
		if (!data->op_out)
			data->op_out = 3;
		if (data->flag)
			executor(data);
		clear_variables(data);
		*cmd = 0;
		data->op_in = 3;
		*pipe = 1;
	}
	return (0);
}

int	working_cmd5(t_data *data, char **token)
{
	data->op_out = 2;
	free(*token);
	*token = next_token(data);
	if (is_operator(*token))
	{
		if (*token == NULL)
		{
			printf_error("ToxicShell: syntax error near unexpected ");
			printf_error("token 'newline'\n");
		}
		else
		{
			printf_error("ToxicShell: syntax error near unexpected token '");
			printf_error(*token);
			printf_error("'\n");
		}
		free(*token);
		clear_variables(data);
		return (1);
	}
	free(data->file_out);
	data->file_out = *token;
	create_file(data->file_out, 2);
	return (0);
}
