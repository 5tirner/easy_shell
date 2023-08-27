#include "simple_shell.h"

/**
 * ft_dup - get a duplicate of a str
 * @s: string
 *
 * Return: A new adrees or NUll if malloc Failed
 */

char	*ft_dup(char *s)
{
	int	i;
	char	*d;

	d = malloc(ft_len(s) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/**
 * join - join the path with the command
 * @path: path
 * @cmd: command
 *
 * Return: The two string joined or NULL
 */

char	*join(char *path, char *cmd)
{
	char	*all;
	int	i;
	int	j;

	path = add_char(path, '/');
	all = malloc(ft_len(path) + ft_len(cmd) + 1);
	if (!all)
		return (NULL);
	i = 0;
	j = 0;
	while (path[i])
	{
		all[j] = path[i];
		i++;
		j++;
	}
	i = 0;
	while (cmd[i])
	{
		all[j] = cmd[i];
		i++;
		j++;
	}
	if (path)
		free(path);
	all[j] = '\0';
	return (all);
}

/**
 * search_in_path - check the path to find the command
 * @cmd: cmd to check it
 * @path: path to check on it
 *
 * Return: the right command if found it, NULL else
 */

char	*search_in_path(char *cmd, char **path)
{
	int	i;
	char	*new_cmd;
	char	*s;

	i = 0;
	while (path[i])
	{
		s = NULL;
		s = ft_dup(path[i]);
		if (!s)
			return (NULL);
		new_cmd = join(s, cmd);
		if (!new_cmd)
			return (NULL);
		if (access(new_cmd, F_OK) == 0)
			return (new_cmd);
		free(new_cmd);
		i++;
	}
	return (NULL);
}

/**
 * go_exec - execute the commands
 * @args: the commande with th argements to execute it
 * @env: enverment variables
 * @path: to check the commands
 * @prog_name: to generate error
 *
 * Return: 1 if execve failed
 */

void	go_exec(char **args, char **env, char **path, char *prog_name)
{
	char	*to_execute;

	if (!args[0])
		return;
	if (access(args[0], F_OK) == -1)
	{
		to_execute = search_in_path(args[0], path);
		if (!to_execute)
		{
			error_generate(prog_name);
			exit(0);
		}
		args[0] = to_execute;
	}
	execve(args[0], args, env);
}

/**
 * exec - execute the args
 * @args: argement to execute
 * @env: enverment variables
 * @path: contains the files
 * @prog_name: av[0] to generate error with it
 *
 * Return: if execve fail will return 0
 */

int	exec(char **args, char **env, char **path, char *prog_name)
{
	int	i;
	char	**cmd;

	i = 0;
	while (1)
	{
		cmd = NULL;
		if (!args[i])
			break;
		if (check_builtins(args[i]))
		{
			built_ins(args[i], env, prog_name, path);
			i++;
			continue;
		}
		cmd = split(args[i], ' ');
		i++;
		if (!args[i] || !ft_strcmp(args[i], ";"))
		{
			if (!fork())
				go_exec(cmd, env, path, prog_name);
			else
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
		}
		delete_2d(cmd);
	}
	return (0);
}
