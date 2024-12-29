/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaimi <azaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 02:02:18 by azaimi            #+#    #+#             */
/*   Updated: 2024/12/28 21:39:03 by azaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sent_signal(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(400);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;
	char	*string;

	i = 0;
	if (argc != 3)
		return (write(1, "Expected: ./<name_program> <PID> <STRING>", 41), -1);
	pid = ft_atoi(argv[1]);
	if (!ft_is_numeric(argv[1]) || kill(pid, 0) == -1 || pid < 0)
	{
		write(1, "There's a problem here:", 23);
		write(1, "./<name_program> <PID> <STRING>\n", 32);
		write(1, "------------------------------------------^\n", 44);
		return (-1);
	}
	string = argv[2];
	while (string[i] != '\0')
	{
		sent_signal(pid, string[i]);
		i++;
	}
	sent_signal(pid, '\0');
	return (0);
}
