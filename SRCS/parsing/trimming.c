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

void	trimming4(t_data *data)
{
	if (data->i > 0)
	{
		if (data->line[data->i - 1] != ' ')
		{
			data->space = 0;
			data->tmp[data->j] = ' ';
			data->j++;
		}
	}
	data->tmp[data->j] = '<';
	data->j++;
}

void	trimming3(t_data *data)
{
	if (data->i > 0)
	{
		if (data->line[data->i - 1] != ' ')
		{
			data->space = 0;
			data->tmp[data->j] = ' ';
			data->j++;
		}
	}
	data->tmp[data->j] = '|';
	data->j++;
	if (data->line[data->i + 1] != '\0')
	{
		data->space = 0;
		data->tmp[data->j] = ' ';
		data->j++;
	}
}

void	trimming2(t_data *data)
{
	if (data->inside)
	{
		data->tmp[data->j] = data->line[data->i];
		data->j++;
	}
	else
	{
		if (data->space)
		{
			data->space = 0;
			data->tmp[data->j] = ' ';
			data->j++;
		}
	}
}

void	trimming12(t_data *data, int echo)
{
	if ((data->line[data->i] >= 9 && data->line[data->i] <= 13)
		|| data->line[data->i] == ' ')
		trimming2(data);
	else if (data->line[data->i] == '|' && !data->inside)
		trimming3(data);
	else if (data->line[data->i] == '<' && !data->inside)
	{
		trimming4(data);
		trimming5(data);
	}
	else if (data->line[data->i] == '>' && !data->inside)
	{
		trimming6(data);
		trimming7(data);
	}
	else if (data->line[data->i] == 34)
		trimming8(data, echo);
	else if (data->line[data->i] == 39)
		trimming9(data, echo);
	else
		trimming10(data);
	data->i++;
}

void	trimming(t_data *data, int echo)
{
	data->tmp = ft_calloc(1, ft_strlen(data->line) * 3 + 1);
	data->i = 0;
	data->j = 0;
	data->space = 0;
	data->inside = 0;
	while (data->line[data->i])
		trimming12(data, echo);
	trimming11(data);
}
