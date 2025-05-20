/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:01:28 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/20 20:21:12 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*star_sim(t_sim *sim)
{
	int	i;

	sim->start_time = get_time_ms(); // save simulation start time
	i = 0;
	while (i < sim->philo_num)
	{
		if (pthread_create(&sim->philos[i].thread_id, NULL,
				philo_routine, &sim->philos[i])!= 0)
			error_exit("Error creating thread");
		i++;
	}
	if (pthread_create(&sim->monitor_thread, NULL,
			monitor_simulation, sim) != 0)
		error_exit("Error creating monitor thread");
	return (NULL);
}

void	join_threads(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_num)
	{
		pthread_join(sim->philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(sim->monitor_thread, NULL);
}

void	*monitor_simulation(void *arg)
{
	t_sim	*sim;


	sim = (t_sim *)arg;
	while (!simulation_has_ended(sim))
	{
		check_philo_death(sim);
		check_all_full(sim);
		usleep(500);
	}
	return (NULL);
}

void	check_philo_death(t_sim *sim)
{
	int		i;
	long	now;
	long	time_since_last_meal;
	t_philo	*philo;

	i = 0;
	while (i < sim->philo_num && !simulation_has_ended(sim))
	{
		philo = &sim->philos[i];
		pthread_mutex_lock(&philo->meal_lock);
		now = get_time_ms();
		time_since_last_meal = now - philo->last_meal_time;
		pthread_mutex_unlock(&philo->meal_lock);
		if (time_since_last_meal > sim->time_to_die)
		{
			pthread_mutex_lock(&sim->end_lock);
			sim->end_simulation = true;
			pthread_mutex_unlock(&sim->end_lock);
			pthread_mutex_lock(&sim->print_lock);
			printf("At %ld ms after sim began, philosopher %d died\n",
				now - sim->start_time, philo->id);
			pthread_mutex_unlock(&sim->print_lock);
			return ;
		}
		i++;
	}
}

void	check_all_full(t_sim *sim)
{
	int	i;
	int	full_count;

	i = 0;
	full_count = 0;
	while (i < sim->philo_num)
	{
		pthread_mutex_lock(&sim->philos[i].meal_lock);
		if (sim->philos[i].full)
			full_count++;
		pthread_mutex_unlock(&sim->philos[i].meal_lock);
		i++;
	}
	if (full_count == sim->philo_num)
	{
		pthread_mutex_lock(&sim->end_lock);
		sim->end_simulation = true;
		pthread_mutex_unlock(&sim->end_lock);
		pthread_mutex_lock(&sim->print_lock);
		printf("All philosophers are full\n");
		pthread_mutex_unlock(&sim->print_lock);
	}
}
