 #include "simple_shell.h"

/**
 * delete_2d - to free the two dem arrays
 * @a: array
 *
 * Return: nothing
 */

void	delete_2d(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
}
/**
 * get_path - get path from env
 * @env: contains PATH
 *
 * Return: path or NULL in case of 'UNSET PATH'
 */

char	**get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

/**
 * check_empty_cmd - check this one " ls" | "ls " | "  "
 * @str: the cmd
 *
 * Return: 1 if the type of cmd like this "    ", o otw
 */

int	check_empty_cmd(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != '\"' && str[i] != '\'')
		return (0);
	i++;
	if (!str[i] || str[i] == ' ')
		return (1);
	if ((str[i] == '\'' || str[i] == '\"') && (!str[i + 1]))
		return (1);
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

/**
 * main - code start
 * @ac: number of args
 * @av: content of args
 * @env: enverment variables
 *
 * Return: no need but i will set it to 0
 */

int	main(int ac, char **av, char **env)
{
	char	*str;
	size_t	buffersize;
	list	*lexer;
	char	**args;
	char	**path;

	(void)ac;
	path = get_path(env);
	while (1)
	{
		str = NULL;
		lexer = NULL;
		args = NULL;
		buffersize = 0;
		write(0, "($) ", 4);
		if (getline(&str, &buffersize, stdin) < 0)
		{
			delete_2d(path);
			free(str);
			return (0);
		}
		if (!str || !str[0] || str[0] == '\n')
		{
			if (str)
				free(str);
			continue;
		}
		lexer = lexecal_analyzer(str);
		if (!lexer)
			return (write(2, "lexer fails\n", 12));
		args = create_args(lexer);
		delete_lexer(lexer);
		if (!args)
			return (write(2, "malloc fails\n", 13));
		i_do_the_work(args, path, env, av[0]);
		delete_2d(args);
		free(str);
	}
	return (0);
}
