#include "simple_shell.h"

/**
 * ft_count_words - conting how many word
 * @str: the line
 * @c: delemitre
 *
 * Return: nbr of words
 */

int	ft_count_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i]) && (str[i] == c))
			i++;
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			j += 1;
		}
	}
	return (j);
}

/**
 * word_len - len of a string
 * @str: the str
 * @c: delemetre
 *
 * Return: len of str
 */

int	word_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

/**
 * ft_free_allocation - to free the allocation
 * @s: 2d array to free it
 * @k: from where should i free
 *
 * Return: Always NULL
 */

char	**ft_free_allocation(char **s, int k)
{
	while (k >= 0)
	{
		free(s[k]);
		k--;
	}
	free(s);
	return (NULL);
}

/**
 * split - to convert a str to 2D array following'c'
 *
 * @s1: the string
 * @c: delemetre
 *
 * Return: New address or NULL if Somthing wrong
 */

char	**split(char const *s1, char c)
{
	char	**arr;
	int		k;
	int		j;

	k = 0;
	if (s1 == NULL)
		return (NULL);
	arr = (char **)ft_calloc((ft_count_words(s1, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s1)
	{
		while (*s1 && *s1 == c)
			s1++;
		if (*s1)
		{
			arr[k] = (char *)ft_calloc(word_len(s1, c) + 1, sizeof(char));
			if (!arr[k++])
				return (ft_free_allocation(arr, k - 1));
			j = 0;
			while (*s1 && (*s1 != c))
				arr[k - 1][j++] = *(s1++);
		}
	}
	return (arr);
}
