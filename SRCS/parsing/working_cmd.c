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

int	working_cmd4(t_data *data, char **token)
{
	data->op_out = 1;
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
	create_file(data->file_out, 1);
	return (0);
}

int	working_cmd3(t_data *data, char **token)
{
	data->op_in = 2;
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
	free(data->delim);
	data->delim = *token;
	return (0);
}

int	working_cmd2(t_data *data, char **token)
{
	data->op_in = 1;
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
	free(data->file_in);
	data->file_in = *token;
	return (0);
}

int	working_cmd9(t_data *data, char **token, int *pipe, int *cmd)
{
	if (!strcmp(*token, "<"))
		return (working_cmd2(data, token));
	else if (!strcmp(*token, "<<"))
		return (working_cmd3(data, token));
	else if (!strcmp(*token, ">"))
		return (working_cmd4(data, token));
	else if (!strcmp(*token, ">>"))
		return (working_cmd5(data, token));
	else if (!strcmp(*token, "|"))
		return (working_cmd6(data, token, pipe, cmd));
	else
		return (working_cmd7(data, token, pipe, cmd));
	return (0);
}

int	working_cmd(t_data *data)
{
	char	*token;
	int		cmd;
	int		pipe;

	token = next_token(data);
	cmd = 0;
	pipe = 0;
	data->tmp_file_in = 0;
	data->tmp_file_out = 0;
	clear_variables(data);
	while (token != NULL)
	{
		if (working_cmd9(data, &token, &pipe, &cmd))
			return (1);
		token = next_token(data);
	}
	if (working_cmd8(data, &pipe))
		return (1);
	return (0);
}
