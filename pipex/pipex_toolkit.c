/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_toolkit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 02:28:12 by mm-isa            #+#    #+#             */
/*   Updated: 2024/03/24 03:55:38 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	handle_cmd(int original, char *cmd_raw, char **env)
{
	char	*cmd_path;
	char	**cmd_array;

	cmd_array = cmd_parse(cmd_raw);
	cmd_path = pathfinder(cmd_array[0], env);
	if (!cmd_path)
	{
		exit_error(original, cmd_array, NULL, cmd_array[0]);
	}
	if (execve(cmd_path, cmd_array, env) == -1)
	{
		exit_error(original, cmd_array, cmd_path, strerror(errno));
	}
	else
	{
		clean_cache(cmd_array);
		clean_cache(&cmd_path);
		exit(EXIT_SUCCESS);
	}
}

char	**cmd_parse(char *cmd_raw)
{
	char	**cmd_arr;

	cmd_arr = ft_split(cmd_raw, ' ');
	if (!cmd_arr)
		return (NULL);
	return (cmd_arr);
}

char	*pathfinder(char *cmd, char **envp)
{
	char	**env_paths;
	char	*which_path;
	char	*match;
	int		idx;

	idx = 0;
	while (ft_strnstr(envp[idx], "PATH=", 5) == 0)
		idx++;
	env_paths = ft_split(envp[idx] + 5, ':');
	idx = 0;
	while (env_paths[idx])
	{
		which_path = ft_strjoin (env_paths[idx], "/");
		match = ft_strjoin(which_path, cmd);
		free(which_path);
		if (access(match, F_OK) == 0)
		{
			clean_cache(env_paths);
			return (match);
		}
		free(match);
		idx++;
	}
	clean_cache(env_paths);
	return (NULL);
}

/*in case *str is passed into clean_cache as an address*/
/*line 92 is separated out as a final check of **junk*/

void	clean_cache(char **junk)

{
	int	i;

	i = 0;
	if (*junk)
	{
		while (junk[i])
		{
			free(junk[i]);
			i++;
		}
	}
	if (junk)
		free(junk);
	else
		return ;
}

void	exit_error(int original, char **arr, char *cmd_str, char const *msg)
{
	if (original)
		dup2(original, STDOUT_FILENO);
	if (msg && arr)
		ft_printf("%s: command not found\n", msg);
	if (arr)
		clean_cache(arr);
	if (cmd_str)
		clean_cache(&cmd_str);
	exit(EXIT_FAILURE);
}
