/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:33:51 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/16 22:17:18 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id_philo;
	int				l_fork;
	int				r_fork;
	struct timeval	last_meal;
	struct timeval	iyctlotpd;
	suseconds_t		time_since_eat;
	int				times_eaten;
	int				is_eating;
	pthread_t		thread_id;
	struct s_info	*info_pointer;
}	t_philo;

// suseconds_t Used for time in microseconds
// meals: nbr of meals bfore stoping. if notdef -1
typedef struct s_info
{
	int				nb;
	suseconds_t		tdie;
	suseconds_t		teat;
	suseconds_t		tsleep;
	int				meals;
	struct timeval	start;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	printer;
	pthread_mutex_t	death;
	t_philo			*phil;
}	t_info;

/* utils */
int				ft_atoi(const char *str);
/* error */
int				error_management(int argc, char **argv);
/* init */
int				iniciator(char **argv, t_info *info_ptr);
/* init */
void			*dinner(void *phi);
int				init_mutex(t_info *info_ptr);
/* time */
struct timeval	time_sum(struct timeval a, suseconds_t b);
unsigned long	timeval_to_useconds(struct timeval tv);
suseconds_t		time_dif(struct timeval b);
/* threads */
void			*check_death_id(void *phi);
void			*check_meal(void *info_void);
/* utils */
int				printing(t_philo *phi, char *str, int b);
#endif
