/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:38:18 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 18:31:16 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sort_export5(int no_equal, char *tmp)
{
	if (no_equal)
		printf("declare -x %s\"\"\n", tmp);
	else
		printf("declare -x %s\n", tmp);
}

void	sort_export4(t_data *data, int i, int e, int no_equal)
{
	char	*tmp;

	while (data->new_env2[e])
	{
		i = 0;
		while (data->new_env2[e][i] != '=' && data->new_env2[e][i])
			i++;
		tmp = ft_strdup2(data->new_env2[e]);
		no_equal = 0;
		if (tmp[i] == '=')
		{
			i++;
			no_equal = 1;
		}
		tmp[i] = '\0';
		if (data->new_env2[e][i] != '\0')
			printf("declare -x %s\"%s\"\n", tmp, &data->new_env2[e][i]);
		else
			sort_export5(no_equal, tmp);
		free(tmp);
		e++;
	}
}

void	sort_export3(t_data *data, int i, int j)
{
	char	*tmp;
	char	*s1;
	char	*s2;

	while (i > 0)
	{
		j = 0;
		while (data->new_env2[j + 1])
		{
			s1 = ft_strdup2(data->new_env2[j]);
			str_no_equal(s1);
			s2 = ft_strdup2(data->new_env2[j + 1]);
			str_no_equal(s2);
			if (ft_strcmp(s1, s2) > 0)
			{
				tmp = data->new_env2[j];
				data->new_env2[j] = data->new_env2[j + 1];
				data->new_env2[j + 1] = tmp;
			}
			free(s1);
			free(s2);
			j++;
		}
		i--;
	}
}

int	sort_export2(t_data *data)
{
	int	i;

	i = 0;
	while (data->new_env[i])
		i++;
	data->new_env2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (data->new_env[i])
	{
		data->new_env2[i] = ft_strdup2(data->new_env[i]);
		i++;
	}
	data->new_env2[i] = NULL;
	return (i);
}

void	sort_export(t_data *data)
{
	int		i;

	i = sort_export2(data);
	sort_export3(data, i, 0);
	sort_export4(data, 0, 0, 0);
	i = 0;
	while (data->new_env2[i])
	{
		free(data->new_env2[i]);
		i++;
	}
	free(data->new_env2);
}
