/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:00:33 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/16 22:13:32 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_chopsticks(t_philo *phi_ptr)
{
	pthread_mutex_lock(&phi_ptr->info_pointer->mutex_fork[phi_ptr->l_fork]);
	printing(phi_ptr, "picked up his left chopstick", 1);
	pthread_mutex_lock(&phi_ptr->info_pointer->mutex_fork[phi_ptr->r_fork]);
	printing(phi_ptr, "picked up his right chopstick", 1);
}

void	eat(t_philo *phi_ptr)
{
	phi_ptr->is_eating = 1;
	printing(phi_ptr, "is eating", 1);
	gettimeofday(&phi_ptr->last_meal, NULL);
	phi_ptr->iyctlotpd = time_sum(phi_ptr->last_meal,
			phi_ptr->info_pointer->tdie * 1000);
	phi_ptr->times_eaten++;
	usleep(phi_ptr->info_pointer->teat * 1000);
	phi_ptr->is_eating = 0;
}

void	leave_chopsticks(t_philo *phi_ptr)
{
	printing(phi_ptr, "is sleeping", 1);
	pthread_mutex_unlock(&phi_ptr->info_pointer->mutex_fork[phi_ptr->l_fork]);
	pthread_mutex_unlock(&phi_ptr->info_pointer->mutex_fork[phi_ptr->r_fork]);
	usleep(phi_ptr->info_pointer->tsleep * 1000);
	printing(phi_ptr, "is thinking", 1);
}

//if you cross this limit of time philosopher die -> iyctlotpd
void	*dinner(void *phi)
{
	t_philo		*phi_ptr;
	pthread_t	th_check_death_id;

	phi_ptr = (t_philo *)phi;
	phi_ptr->last_meal = phi_ptr->info_pointer->start;
	phi_ptr->iyctlotpd = time_sum(phi_ptr->last_meal,
			phi_ptr->info_pointer->tdie * 1000);
	pthread_create(&th_check_death_id, NULL, &check_death_id, phi);
	pthread_detach(th_check_death_id);
	if (phi_ptr->id_philo % 2 == 0)
		usleep(550);
	while (1)
	{
		pick_chopsticks(phi_ptr);
		eat(phi_ptr);
		leave_chopsticks(phi_ptr);
	}
	return (NULL);
}
