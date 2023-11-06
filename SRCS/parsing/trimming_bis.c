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

void	trimming9(t_data *data, int echo)
{
	if (!data->inside)
	{
		if (!echo)
		{
			data->tmp[data->j] = data->line[data->i];
			data->j++;
		}
		data->inside = 1;
	}
	else if (data->inside == 1)
	{
		if (!echo)
		{
			data->tmp[data->j] = data->line[data->i];
			data->j++;
		}
		data->inside = 0;
	}
	else
	{
		data->tmp[data->j] = data->line[data->i];
		data->j++;
	}
}

void	trimming8(t_data *data, int echo)
{
	if (!data->inside)
	{
		if (!echo)
		{
			data->tmp[data->j] = data->line[data->i];
			data->j++;
		}
		data->inside = 2;
	}
	else if (data->inside == 2)
	{
		if (!echo)
		{
			data->tmp[data->j] = data->line[data->i];
			data->j++;
		}
		data->inside = 0;
	}
	else
	{
		data->tmp[data->j] = data->line[data->i];
		data->j++;
	}
}

void	trimming7(t_data *data)
{
	if (data->line[data->i + 1] == '>')
	{
		data->i++;
		data->tmp[data->j] = '>';
		data->j++;
		if (data->line[data->i + 1] != '\0')
		{
			data->space = 0;
			data->tmp[data->j] = ' ';
			data->j++;
		}
	}
	else if (data->line[data->i + 1] != '\0')
	{
		data->space = 0;
		data->tmp[data->j] = ' ';
		data->j++;
	}
}

void	trimming6(t_data *data)
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
	data->tmp[data->j] = '>';
	data->j++;
}

void	trimming5(t_data *data)
{
	if (data->line[data->i + 1] == '<')
	{
		data->i++;
		data->tmp[data->j] = '<';
		data->j++;
		if (data->line[data->i + 1] != '\0')
		{
			data->space = 0;
			data->tmp[data->j] = ' ';
			data->j++;
		}
	}
	else if (data->line[data->i + 1] != '\0')
	{
		data->space = 0;
		data->tmp[data->j] = ' ';
		data->j++;
	}
}
