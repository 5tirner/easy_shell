#include "simple_shell.h"

/**
 * error_generate - genrate an error
 * @prog_name: av[0]
 *
 * Return: Nothing
 */

void	error_generate(char *prog_name)
{
	write(2, prog_name, ft_len(prog_name));
	write(2, ": No such file or directory\n", 28);
}
