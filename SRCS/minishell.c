/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:44 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 14:04:58 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_tsh_pid = 0;

int	main(int argc, char *argv[], char *env[])
{
	t_data				data;

	(void)argc;
	(void)argv;
	signal(SIGINT, &handle_int);
	signal(SIGQUIT, &handle_quit);
	init(&data, env);
	parser(&data);
	return (EXIT_SUCCESS);
}
