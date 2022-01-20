/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:44:33 by mszczerb          #+#    #+#             */
/*   Updated: 2021/05/24 19:53:37 by mszczerb         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[12];
	int		i;
	long	number;

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
	write(fd, buffer, ft_strlen(buffer));
}
