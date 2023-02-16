/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:01:32 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/15 22:04:29 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	time_sum(struct timeval a, suseconds_t b)
{
	struct timeval	c;

	c.tv_usec = b + a.tv_usec;
	if (c.tv_usec < 1000000)
		c.tv_sec = a.tv_sec;
	else
	{
		c.tv_sec = a.tv_sec + 1;
		c.tv_usec = c.tv_usec - 1000000;
	}
	return (c);
}

unsigned long	timeval_to_useconds(struct timeval tv)
{
	return ((tv.tv_sec * (unsigned long) 1000) + (tv.tv_usec / 1000));
}

suseconds_t	time_dif(struct timeval b)
{
	struct timeval	a;

	gettimeofday(&a, NULL);
	return (a.tv_usec - b.tv_usec + (a.tv_sec - b.tv_sec) * 1000000);
}
