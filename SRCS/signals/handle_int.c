/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:44 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 16:07:36 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern pid_t	g_tsh_pid;

void	handle_int(int sig)
{
	(void)sig;
	if (g_tsh_pid)
	{
		kill(g_tsh_pid, SIGQUIT);
		printf("^C\n");
	}
	else
	{
		printf("\r");
		printf(PROMPT);
		printf("%s", rl_line_buffer);
		printf("^C\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_tsh_pid = 0;
}
