/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:14:41 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/08/04 18:18:22 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	ft_free(void *ptr)
{
	t_gc	**list;
	t_gc	*lst;
	t_gc	*tmp;

	free(ptr);
	list = ft_get_gc_list();
	if (!list || !*list)
		return ;
	lst = *list;
	if (lst->content == ptr)
	{
		*list = lst->next;
		tmp = lst;
	}
	else
	{
		while (lst->next && lst->next->content != ptr)
			lst = lst->next;
		tmp = lst->next;
		if (tmp)
			lst->next = lst->next->next;
	}
	free(tmp);
}

void	ft_free_all(void)
{
	t_gc	**list;
	t_gc	*curr;
	t_gc	*next;

	list = ft_get_gc_list();
	curr = *list;
	while (curr)
	{
		next = curr->next;
		free(curr->content);
		free(curr);
		curr = next;
	}
	*list = NULL;
}
