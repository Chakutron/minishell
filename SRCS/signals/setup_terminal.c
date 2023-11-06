/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:44 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 16:08:44 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	setup_terminal(t_data *data)
{
	struct termios	new_attributes;

	tcgetattr(STDIN_FILENO, &data->original_attributes);
	new_attributes = data->original_attributes;
	new_attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_attributes);
}
