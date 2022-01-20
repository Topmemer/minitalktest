/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczerb <mszczerb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:26:20 by mszczerb          #+#    #+#             */
/*   Updated: 2022/01/20 15:35:58 by mszczerb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void	send_byte(int char_to_send, int pid, int bites)
{
	if (bites > 1)
		send_byte(char_to_send >> 1, pid, bites - 1);
	send_bit(char_to_send % 2, pid);
}

void	send_bit(int bite, int pid)
{
	if (bite == 0)
			kill(pid, SIGUSR1);
	else
			kill(pid, SIGUSR2);
	usleep(1000);
}

void	handle_usr(int signum)
{
	
}

int	main(int argc, char **argv)
{
	char *string;
	int i;
	int pid;
	signal(SIGUSR1, handle_usr);
	signal(SIGUSR2, handle_usr);
	if(argc < 2)
	{
		write(1, "pid of server not specified, aborting\n", 39);
		exit(EXIT_FAILURE);
	}
	if(argc < 3)
	{
		write(1, "nothing to send, aborting\n", 27);
		exit(EXIT_FAILURE);
	}
	string = argv[2];
	i = 0;
	pid = atoi(argv[1]);
	send_byte(strlen(string), pid, sizeof(unsigned long)*8);
	while (1)
	{
		send_byte(string[i], pid, 8);
		i++;
		if (string[i] == '\0')
			break;
	}
	send_byte('\0', pid, 8);
	exit(EXIT_SUCCESS);
}
