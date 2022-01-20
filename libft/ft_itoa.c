/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:17:56 by mszczerb          #+#    #+#             */
/*   Updated: 2021/05/24 19:08:38 by mszczerb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_helper(char *buffer, long number)
{
	int	i;

	i = 0;
	if (number >= 10)
		i = itoa_helper(buffer, number / 10);
	buffer[i] = number % 10 + '0';
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	buffer[12];
	int		i;
	long	number;
	char	*ptr;

	ft_bzero(buffer, 12);
	i = 0;
	number = n;
	if (n < 0)
	{
		buffer[i] = '-';
		i++;
		number *= -1;
	}
	itoa_helper(&buffer[i], number);
	ptr = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	ft_strlcpy(ptr, buffer, ft_strlen(buffer) + 1);
	return (ptr);
}
