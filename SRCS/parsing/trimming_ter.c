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

void	trimming11(t_data *data)
{
	if (data->inside == 2)
	{
		printf_error("ToxicShell: dquote> error\n");
		data->line_error = 1;
	}
	else if (data->inside == 1)
	{
		printf_error("ToxicShell: quote> error\n");
		data->line_error = 1;
	}
	if (data->j > 0 && data->tmp[data->j - 1] == ' ')
		data->tmp[data->j - 1] = '\0';
	else
		data->tmp[data->j] = '\0';
	free(data->line);
	data->line = data->tmp;
}

void	trimming10(t_data *data)
{
	data->space = 1;
	data->tmp[data->j] = data->line[data->i];
	data->j++;
}
