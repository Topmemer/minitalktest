/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:10:39 by mszczerb          #+#    #+#             */
/*   Updated: 2021/05/23 14:32:02 by mszczerb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*ptr;

	ptr = (char *) big;
	i = 0;
	j = 0;
	size = ft_strlen(little);
	if (size == 0)
		return (ptr);
	if (len < size)
		return (0);
	while (i < len - size + 1 && ptr[i] != 0)
	{
		j = 0;
		while (j < size && ptr[i + j] == little[j])
		{
			j++;
			if (j == size)
				return (&ptr[i]);
		}
		i++;
	}
	return (0);
}
