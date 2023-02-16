/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:36:34 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/16 18:04:26 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	dest;
	int				sign;

	i = 0;
	dest = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-'
			|| str[i + 1] == '+'))
		return (0);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		dest = dest * 10;
		dest = dest + str[i] - 48;
		i++;
	}
	return (dest * sign);
}

int	printing(t_philo *phi, char *str, int flag)
{
	suseconds_t		now_time;

	pthread_mutex_lock(&phi->info_pointer->printer);
	now_time = time_dif(phi->info_pointer->start);
	printf("%dms philo %d %s!\n", now_time / 1000, phi->id_philo, str);
	if (flag == 1)
		pthread_mutex_unlock(&phi->info_pointer->printer);
	return (0);
}
