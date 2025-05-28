/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:42:42 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/27 18:55:18 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

bool	simulation_has_ended(t_sim *sim)
{
	bool	ended;

	pthread_mutex_lock(&sim->end_lock);
	ended = sim->end_simulation;
	pthread_mutex_unlock(&sim->end_lock);
	return (ended);
}

void	print_action(t_philo *philo, const char *action)
{
	pthread_mutex_lock(&philo->sim->print_lock);
	if (!simulation_has_ended(philo->sim))
	{
		printf(" %ld %d %s\n",
			get_time_ms() - philo->sim->start_time,
			philo->id, action);
	}
	pthread_mutex_unlock(&philo->sim->print_lock);
}

void	one_philo(t_philo *philo)
{
	print_action(philo, "has taken a fork");
	usleep(philo->sim->time_to_die * 1000);
	return ;
}
