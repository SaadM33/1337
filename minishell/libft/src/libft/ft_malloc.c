/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:46:53 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:28 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_get_list(void)
{
	static t_list	*list = NULL;

	return (&list);
}

void	*ft_malloc(size_t size)
{
	t_list	**list;
	t_list	*node;
	void	*ptr;

	ptr = malloc(size);
	list = ft_get_list();
	if (ptr)
	{
		node = ft_lstnew(ptr);
		if (node)
			return (ft_lstadd_back(list, node), ptr);
		free(ptr);
	}
	perror("minishell: malloc");
	ft_exit(2);
	return (NULL);
}

void	ft_free(void *ptr)
{
	t_list	**list;
	t_list	*lst;
	t_list	*tmp;

	free(ptr);
	list = ft_get_list();
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
