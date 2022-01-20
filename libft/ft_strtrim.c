/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:28:29 by mszczerb          #+#    #+#             */
/*   Updated: 2021/05/23 14:31:17 by mszczerb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*ptr;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (i < end && ft_strchr(set, s1[i]) != NULL)
		i++;
	start = i;
	i = end;
	while (i > start && ft_strchr(set, s1[i - 1]) != NULL)
		i--;
	end = i;
	ptr = malloc(sizeof(char) * (end - start + 1));
	ft_strlcpy(ptr, &s1[start], end - start + 1);
	return (ptr);
}
