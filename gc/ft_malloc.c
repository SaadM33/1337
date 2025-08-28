/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:03:29 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/08/04 18:40:01 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_gc	**ft_get_gc_list(void)
{
	static t_gc	*list = NULL;

	return (&list);
}

void	*ft_malloc(size_t size)
{
	t_gc	**list;
	t_gc	*node;
	void	*ptr;

	ptr = malloc(size);
	list = ft_get_gc_list();
	if (ptr)
	{
		node = ft_gc_new(ptr);
		if (node)
			return (ft_gc_add_node(list, node), ptr);
		free(ptr);
	}
	perror("malloc");
	ft_free_all();
	exit(EXIT_FAILURE);
	return (NULL);
}

t_gc	*ft_gc_new(void *content)
{
	t_gc	*node;

	node = malloc(sizeof(t_gc));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_gc_add_node(t_gc **list, t_gc *node)
{
	t_gc	*current;

	if (!list || !node)
		return ;
	if (!*list)
	{
		*list = node;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = node;
}
