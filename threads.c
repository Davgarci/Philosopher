/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:09:47 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/16 22:10:35 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death_id(void *phi)
{
	t_philo			*phi_ptr;
	struct timeval	check_time;

	phi_ptr = (t_philo *)phi;
	while (1)
	{
		gettimeofday(&check_time, NULL);
		if (phi_ptr->is_eating == 0 && (timeval_to_useconds(phi_ptr->iyctlotpd)
				< timeval_to_useconds(check_time)))
		{
			printing(phi_ptr, "has died RIP", 0);
			pthread_mutex_unlock(&phi_ptr->info_pointer->death);
			return ((void *) 0);
		}
		usleep(1000);
	}
	return ((void *) 1);
}

void	*check_meal(void *info_void)
{
	t_info			*info_ptr;
	int				i;

	info_ptr = (t_info *)info_void;
	while (1)
	{
		i = 0;
		while (i < info_ptr->nb)
		{
			if (info_ptr->phil[i].times_eaten >= info_ptr->meals)
			{
				i++;
			}
			else
				break ;
		}
		if (i == info_ptr->nb)
		{
			printing(&info_ptr->phil[i - 1], "has eaten. Everybody ate", 0);
			pthread_mutex_unlock(&info_ptr->death);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}
