/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:51:09 by mszczerb          #+#    #+#             */
/*   Updated: 2022/01/20 15:32:14 by mszczerb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <locale.h>

void	write_and_free_string(char **string, unsigned long *string_index)
{
	write(1, *string, *string_index);
	free(*string);
	*string = NULL;
	*string_index = 0;
}

char	*get_string_size(int signum)
{
	static unsigned int		i = 0;
	static unsigned long	size = 0;
	char					*result;

	result = NULL;
	size = size << 1;
	size += signum / SIGUSR2;
	i++;
	if (i < sizeof(unsigned long) * 8)
		return (NULL);
	else
	{
		result = malloc(sizeof(char) * size + 1);
		i = 0;
		size = 0;
		return (result);
	}
}

void	handle_usr(int signum, siginfo_t *info, void *context)
{
	static unsigned int		i = 0;
	static char				recived_char = 0;
	static char				*recived_string = NULL;
	static unsigned long	string_index = 0;

	if (recived_string == NULL)
		recived_string = get_string_size(signum);
	else
	{
		recived_char = recived_char << 1;
		recived_char += signum / SIGUSR2;
		i++;
		if (i >= 8)
		{
			recived_string[string_index] = recived_char;
			string_index++;
			if (recived_char == '\0')
				write_and_free_string(&recived_string, &string_index);
			i = 0;
			recived_char = 0;
		}
	}
	kill(info->si_pid, signum);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig_action;

	sig_action.sa_sigaction = handle_usr;
	sig_action.sa_flags = SA_SIGINFO;
	pid = getpid();
	printf("pid: %i\n", pid);
	sigaction (SIGUSR1, &sig_action, NULL);
	sigaction (SIGUSR2, &sig_action, NULL);
	while (1)
	{
	}
	return (EXIT_FAILURE);
}
