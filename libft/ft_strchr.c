/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:18:41 by mszczerb          #+#    #+#             */
/*   Updated: 2021/05/23 14:33:38 by mszczerb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	size = ft_strlen(ptr) + 1;
	while (i < size)
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		i++;
	}
	return (0);
}
