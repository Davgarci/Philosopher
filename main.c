/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:26:41 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/16 18:01:36 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*info_ptr;

	info_ptr = malloc(sizeof(t_info));
	if (error_management(argc, argv) == 0)
		exit(0);
	iniciator(argv, info_ptr);
	pthread_mutex_lock(&info_ptr->death);
	return (0);
}
