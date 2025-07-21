/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obentahi <obentahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:18:27 by obentahi          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:22 by obentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !*lst || !del)
		return ;
	if ((*lst)-> next)
		ft_lstclear(&(*lst)->next, del);
	ft_free((*lst)->content);
	*lst = NULL;
}
