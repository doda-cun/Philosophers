/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:40:44 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/27 18:56:52 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulation_init(t_sim *sim)
{
	int	i;

	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->philo_num);
	if (!sim->forks)
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
	sim->start_time = get_time_ms();
	i = 0;
	while (i < sim->philo_num)
	{
		struct_init(sim, i);
		i++;
	}
	pthread_mutex_init(&sim->print_lock, NULL);
	pthread_mutex_init(&sim->end_lock, NULL);
	sim->end_simulation = false;
}

void	struct_init(t_sim *sim, int i)
{
	sim->philos[i].id = i + 1;
	sim->philos[i].meals_eaten = 0;
	sim->philos[i].last_meal_time = sim->start_time;
	sim->philos[i].sim = sim;
	sim->philos[i].left_fork = &sim->forks[i];
	sim->philos[i].right_fork = &sim->forks[(i + 1) % sim->philo_num];
	pthread_mutex_init(&sim->philos[i].meal_lock, NULL);
	sim->philos[i].full = false;
}
