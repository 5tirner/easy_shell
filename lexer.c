#include "simple_shell.h"

/**
 * ft_len - clacul len
 * @str: string
 *
 * Return: len of str
 */

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * add_char - add char to string
 * @buff: the string
 * @c: char to add
 *
 * Return: buff + c or NUll if Allocation failed
 */

char	*add_char(char *buff, char c)
{
	int	i;
	char	*new;

	if (!buff)
	{
		new = malloc(3);
		if (!new)
			return (NULL);
		new[0] = c;
		new[1] = '\0';
	}
	else
	{
		new = malloc(ft_len(buff) + 2);
		if (!new)
			return (NULL);
		i = 0;
		while (buff[i])
		{
			new[i] = buff[i];
			i++;
		}
		new[i] = c;
		new[i + 1] = '\0';
	}
	free(buff);
	return (new);
}

/**
 * lexecal_analyzer - make different types of tokens
 * @str: str to pars
 *
 * Return: lexer or NUll if Somthing fail
 */

list	*lexecal_analyzer(char *str)
{
	list	*lexer;
	int	i;
	char	*buff;

	lexer = NULL;
	i = 0;
	buff = NULL;
	while (1)
	{
		if (!str[i])
			break;
		else if (str[i] == '|')
		{
			buff = add_char(buff, str[i]);
			i++;
		}
		else if (str[i] == ';')
		{
			buff = add_char(buff, str[i]);
			i++;
		}
		else
		{
			while (str[i] && str[i] != '\n' && str[i] != ';' && str[i] != '|')
			{
				if (str[i] != '\"' && str[i] != '\'')
				{
					buff = add_char(buff, str[i]);
					if (!buff)
						return (NULL);
				}
				i++;
			}
		}
		if (str[i] == '\n')
			i++;
		add_back(&lexer, new_node(buff));
		buff = NULL;
	}
	return (lexer);
}
