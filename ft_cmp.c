#include "simple_shell.h"

/**
 * ft_strcmp - to compare two strings
 * @a: the first string
 * @b: second string
 *
 * Return: val of the first diff chars or 0
 */

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] || b[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

/**
 * ft_strncmp - same as ft_strcmp but until reach n
 * @a: first
 * @b: second
 * @n: compare until reach it
 *
 * Return: val of first diff between a and b or 0
 */

int	ft_strncmp(char *a, char *b, int n)
{
	int	i;

	i = 0;
	while ((a[i] || b[i]) && (i < n))
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
