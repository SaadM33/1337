/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maaq <sel-maaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:17:58 by sel-maaq          #+#    #+#             */
/*   Updated: 2025/08/04 21:56:58 by sel-maaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_gc
{
	void		*content;
	struct s_gc	*next;
}		t_gc;

t_gc	**ft_get_gc_list(void);
t_gc	*ft_gc_new(void *content);
void	ft_gc_add_node(t_gc **list, t_gc *node);

void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
void	ft_free_all(void);

#endif