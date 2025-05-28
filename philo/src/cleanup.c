/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:28:11 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/27 19:57:31 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sim_clean(t_sim *sim)
{
	int	i;

	// i = 0;
	// while( i < sim->philo_num)
	// {
	// 	pthread_join(sim->philos[i].thread_id,NULL);
	// 	i++;
	// }
	i = 0;
	while (i < sim->philo_num)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	free(sim->forks);
	i = 0;
	while (i < sim->philo_num)
	{
		pthread_mutex_destroy(&sim->philos[i].meal_lock);
		i++;
	}
	free(sim->philos);
	pthread_mutex_destroy(&sim->print_lock);
	pthread_mutex_destroy(&sim->end_lock);

}
