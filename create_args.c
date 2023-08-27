#include "simple_shell.h"

/**
 * create_args - To behave like the prog take info from argv
 * @lexer: the lexer
 *
 * Return: pointer of pointer to char
 */

char	**create_args(list *lexer)
{
	char	**args;
	int	i;

	args = (char **)malloc(sizeof(char *) * (listsize(lexer) + 1));
	if (!args)
		return (NULL);
	i = 0;
	while (lexer)
	{
		if (!lexer->content)
			args[i] = ft_dup("makaynch");
		else
			args[i] = ft_dup(lexer->content);
		lexer = lexer->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}
