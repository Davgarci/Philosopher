/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:53:43 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/16 22:11:53 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_info *info_ptr)
{
	int		i;

	i = 0;
	pthread_mutex_init(&info_ptr->printer, NULL);
	pthread_mutex_init(&info_ptr->death, NULL);
	info_ptr->mutex_fork = malloc(sizeof(pthread_mutex_t) * info_ptr->nb);
	if (!info_ptr->mutex_fork)
		return (0);
	pthread_mutex_lock(&info_ptr->death);
	while (i <= info_ptr->nb)
	{
		pthread_mutex_init(&info_ptr->mutex_fork[i], NULL);
		i++;
	}
	return (1);
}
