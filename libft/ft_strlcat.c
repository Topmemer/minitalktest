/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:14:40 by mszczerb          #+#    #+#             */
/*   Updated: 2021/05/25 19:03:38 by mszczerb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	start;
	size_t	j;

	start = 0;
	j = 0;
	while (dst[start] != '\0' && start < size)
		start++;
	while (src[j] != '\0' && j + start + 1 < size)
	{
		dst[start + j] = src[j];
		j++;
	}
	if (size != 0 && size > start)
		dst[start + j] = '\0';
	return (start + ft_strlen(src));
}
