#include "simple_shell.h"

/**
 * ft_bzero - to set 0 in s
 * @s: buffer to set it with 0
 * @n: until what we will fill
 *
 * Return: nothing
 */

void	ft_bzero(void *s, size_t n)
{
	char			*str;
	unsigned int	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/**
 * ft_calloc - reproduce calloc
 * @count: count to allocate
 * @size: size to allocate
 *
 * Return: NULL if somthing wrong or new addres
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
