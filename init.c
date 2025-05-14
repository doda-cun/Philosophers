/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:40:44 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/14 20:27:31 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// alloctae nad initialize forks, philos, shared sim values, like start time
// each for must be amutext so only one philo holds it at a time

void init_sim(t_sim *sim)
{
	int i;

	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->philo_num);
	if(!sim->forks)
		error_exit("Failed to allocate fork.\n");
	i = 0;
	while (i < sim->philo_num)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
	sim->philos = malloc(sizeof(t_philo) * sim->philo_num);
	if (!sim->philos)
		error_exit("Failed philosophers allocation.\n");
	i = 0;
	while (i < sim->philo_num)
	{
		sim->philos[i].id = i + 1;
		sim->philos[i].meals_eaten = 0;
		sim->philos[i].last_meal_time = 0;
		sim->philos[i].sim = sim; // lets each philo acces shared datat form their own thread
		sim->philos[i].left_fork = &sim->forks[i];
		sim->philos[i].right_fork = &sim->forks[(i+1) % sim->philo_num];
	}

}
