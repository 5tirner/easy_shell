#include "simple_shell.h"

/**
 * delete_lexer - free lexer
 * @lexer: lexecal analyzer
 *
 * Return: void
 */

void	delete_lexer(list *lexer)
{
	list	*save;

	while (lexer)
	{
		save = lexer->next;
		free(lexer->content);
		free(lexer);
		lexer = save;
	}
}
