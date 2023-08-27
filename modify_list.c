#include "simple_shell.h"

/**
 * new_node - create a new node
 * @content: content to fill node with it
 *
 * Return: the node or NULL
 */

list	*new_node(char	*content)
{
	list	*new;

	new = malloc(sizeof(list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/**
 * add_back - add in back of linked list
 * @lst: the list
 * @node: node to add it
 *
 * Return: Nothing
 */

void	add_back(list **lst, list *node)
{
	list	*head;

	if (!(*lst))
		*lst = node;
	else
	{
		head = (*lst);
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = node;
		*lst = head;
	}
}

/**
 * listsize - calcul size of list
 * @lst: list to calcul it's size
 *
 * Return: len of lst
 */

int	listsize(list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
