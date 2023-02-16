/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:30:24 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/16 22:13:32 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_thread(int i, t_info *info_ptr)
{
	void		*phi;

	phi = (void *)(&info_ptr->phil[i]);
	if (pthread_create(&info_ptr->phil[i].thread_id, NULL, &dinner, phi))
		return (0);
	pthread_detach(info_ptr->phil[i].thread_id);
	usleep(100);
	return (0);
}

int	init_phil(t_info *info_ptr)
{
	int			i;
	pthread_t	th_check_meal;

	i = 0;
	info_ptr->phil = malloc(sizeof(t_philo) * info_ptr->nb);
	while (i < info_ptr->nb)
	{
		info_ptr->phil[i].id_philo = i + 1;
		info_ptr->phil[i].r_fork = i + 1;
		info_ptr->phil[i].l_fork = (i + 1 + 1) % info_ptr->nb;
		gettimeofday(&(info_ptr->phil[i].last_meal), NULL);
		info_ptr->phil[i].time_since_eat = 0;
		info_ptr->phil[i].times_eaten = 0;
		info_ptr->phil[i].is_eating = 0;
		info_ptr->phil[i].info_pointer = info_ptr;
		init_thread(i, info_ptr);
		i++;
	}
	i = 0;
	if (info_ptr->meals > 0)
	{
		pthread_create(&th_check_meal, NULL, &check_meal, (void *)info_ptr);
		pthread_detach(th_check_meal);
	}	
	return (0);
}

int	iniciator(char **argv, t_info *info_ptr)
{
	int	i;

	i = 0;
	info_ptr->nb = ft_atoi(argv[1]);
	info_ptr->tdie = ft_atoi(argv[2]);
	info_ptr->teat = ft_atoi(argv[3]);
	info_ptr->tsleep = ft_atoi(argv[4]);
	if (argv[5])
		info_ptr->meals = ft_atoi(argv[5]);
	else
		info_ptr->meals = -1;
	gettimeofday(&(info_ptr->start), NULL);
	info_ptr->mutex_fork = NULL;
	init_mutex(info_ptr);
	init_phil(info_ptr);
	return (0);
}
