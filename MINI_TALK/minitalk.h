/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaimi <azaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:06:58 by azaimi            #+#    #+#             */
/*   Updated: 2024/12/28 22:01:06 by azaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
int		ft_is_numeric(char *str);

#endif