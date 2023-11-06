/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:15:55 by mchiboub          #+#    #+#             */
/*   Updated: 2023/11/05 18:55:23 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_dir3(void)
{
	if (errno == EACCES)
		printf_error("ToxicShell: Permision denied\n");
	else if (errno == ELOOP)
		printf_error("ToxicShell: Loop encountered in symbolic links\n");
	else if (errno == ENAMETOOLONG)
		printf_error("ToxicShell: Length exceeds the limits\n");
	else if (errno == ENOENT)
		printf_error("ToxicShell: No such directory\n");
	else if (errno == ENOTDIR)
		printf_error("ToxicShell: Not a directory\n");
}

int	change_dir2(t_data *data, int ret)
{
	char	*tmp;

	tmp = getenv2(data, "HOME");
	if (tmp)
	{
		if (tmp[ft_strlen(tmp) - 1] != '/')
			tmp = ft_strcat2(tmp, '/');
		ret = chdir(tmp);
		free(tmp);
	}
	return (ret);
}

int	change_dir(t_data *data, char *dir)
{
	int		ret;
	char	*tmp;

	ret = 0;
	if (dir)
	{
		tmp = ft_strdup2(dir);
		if (tmp[ft_strlen(tmp) - 1] != '/')
			tmp = ft_strcat2(tmp, '/');
		ret = chdir(tmp);
		free(tmp);
	}
	else
		ret = change_dir2(data, ret);
	if (ret == -1)
		change_dir3();
	return (ret);
}
