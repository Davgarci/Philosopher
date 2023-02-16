/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:53:11 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/15 21:48:33 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_management(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		write(1, "Wrong number of arguments\n", 26);
		return (0);
	}
	if (ft_atoi(argv[1]) <= 1 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0 || (argc == 6 && ft_atoi(argv[5]) <= 0))
	{
		write(1, "Non valid arguments\n", 20);
		return (0);
	}
	return (1);
}
