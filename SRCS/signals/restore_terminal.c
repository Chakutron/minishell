/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_terminal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:44 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 16:08:15 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	restore_terminal(t_data *data)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &data->original_attributes);
}
