#include "simple_shell.h"

/**
 * check_builtins - check env and exit
 * @cmd: the command
 *
 * Return: 1 if builtins 0 if not
 */

int	check_builtins(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if ((!ft_strncmp(&cmd[i], "env", 3))
		&& (!cmd[i + 3] || cmd[i + 3] == ' '))
		return (1);
	else if ((!ft_strncmp(&cmd[i], "exit", 4))
		&& (!cmd[i + 4] || cmd[i + 4] == ' '))
		return (2);
	return (0);
}

/**
 * exit_args - to know if i have to exit or not
 * @cmd: exit command
 *
 * Return: Number of argemnts
 */

int	exit_args(char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		while (cmd[i] && cmd[i] == ' ')
			i++;
		if (cmd[i])
		{
			while (cmd[i] && cmd[i] != ' ')
				i++;
			j++;
		}
	}
	return (j);
}

/**
 * env_next - get the part that front of env
 * @cmd: command line
 *
 * Return: the part after env
 */

char	*env_next(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	i += 3;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (cmd[i])
		return (&cmd[i]);
	return (NULL);
}

/**
 * do_env - handle env built in
 * @cmd: the command line
 * @env: env vars
 * @path: the path
 * @prog_name: av[0]
 *
 * Return: nothing
 */

void	do_env(char *cmd, char **env, char **path, char *prog_name)
{
	char	*env_nxt;
	char	**find_file;
	int	i;

	env_nxt = env_next(cmd);
	if (env_nxt)
	{
		find_file = split(env_nxt, ' ');
		if (!find_file)
			return;
		if (search_in_path(find_file[0], path))
		{
			if (!fork())
				go_exec(find_file, env, path, prog_name);
			else
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
		}
		else
			error_generate(prog_name);
		delete_2d(find_file);
	}
	else
	{
		i = -1;
		while (env && env[++i])
		{
			write(1, env[i], ft_len(env[i]));
			write(1, "\n", 1);
		}
	}
}

/**
 * built_ins - handle env and exit
 * @cmd: the command
 * @env: to print the env
 * @prog_name: av[0]
 * @path: the path
 *
 * Return: an int to check if i have to execute the next cmd
 */

int	built_ins(char *cmd, char **env, char *prog_name, char **path)
{
	int	checker;

	checker = check_builtins(cmd);
	if (checker == 2)
	{
		if (exit_args(cmd) > 2)
		{
			write(2, "exit: too many arguments\n", 25);
			return (1);
		}
		else
			exit(0);
	}
	else if (checker == 1)
	{
		do_env(cmd, env, path, prog_name);
		return (1);
	}
	return (0);
}
