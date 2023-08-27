#include "simple_shell.h"

/**
 * i_do_the_work - work on the command lines
 * @cmd: the commands
 * @prog_name: av[0]
 * @path: the path
 * @env: env vars
 *
 * Return: Nothing
 */

void	i_do_the_work(char **cmd, char **path, char **env, char *prog_name)
{
	int	checker;

	if (!cmd[0])
		error_generate(prog_name);
	else if (check_builtins(cmd[0]))
	{
		checker = built_ins(cmd[0], env, prog_name, path);
		if (checker == 1 && cmd[1])
			exec(&cmd[1], env, path, prog_name);
	}
	else
		exec(cmd, env, path, prog_name);
}
