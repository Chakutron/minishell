/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:44 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 16:10:29 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern pid_t	g_tsh_pid;

void	handle_quit(int sig)
{
	(void)sig;
	if (g_tsh_pid)
	{
		kill(g_tsh_pid, SIGQUIT);
		printf("^\\Quit (core dumped)\n");
		g_tsh_pid = 0;
		return ;
	}
	printf("\r");
	printf(PROMPT);
	printf("%s", rl_line_buffer);
	g_tsh_pid = 0;
}
