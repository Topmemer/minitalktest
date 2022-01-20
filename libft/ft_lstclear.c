/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:29:28 by mszczerb          #+#    #+#             */
/*   Updated: 2021/05/23 22:46:52 by mszczerb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*nexttoptr;

	if (lst == NULL)
		return ;
	nexttoptr = *lst;
	while (nexttoptr->next != NULL)
	{
		ptr = nexttoptr;
		nexttoptr = nexttoptr ->next;
		ft_lstdelone(ptr, del);
	}
	ft_lstdelone(nexttoptr, del);
	*lst = NULL;
}
