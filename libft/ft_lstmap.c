/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:45:00 by mszczerb          #+#    #+#             */
/*   Updated: 2021/05/23 22:43:43 by mszczerb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newelement;
	t_list	*result;

	result = ft_lstnew((*f)(lst->content));
	if (result == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst -> next;
		newelement = ft_lstnew((*f)(lst->content));
		if (newelement == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, newelement);
	}
	return (result);
}
