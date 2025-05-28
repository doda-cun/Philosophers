/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:06:39 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/28 17:56:56 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_sim	*sim;

	philo = (t_philo *)arg;
	sim = philo->sim;
	if (philo->id % 2 == 0)
		usleep(500);
	if (sim->philo_num == 1)
		return (one_philo(philo), NULL);
	while (!simulation_has_ended(sim))
	{
		take_forks(philo);
		philo_eat(philo);
		if (simulation_has_ended(sim))
			break ;
		philo_sleep(philo);
		if (simulation_has_ended(sim))
			break ;
		philo_think(philo);
	}
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a right fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a left fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a left fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a right fork");
	}
}

void	philo_eat(t_philo *philo)
{
	if ((philo->meals_eaten == philo->sim->meals_required)
		|| simulation_has_ended(philo->sim))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	print_action(philo, "is eating");
	usleep(philo->sim->time_to_eat * 1000);
	philo->meals_eaten++;
	if (philo->sim->meals_required > 0
		&& philo->meals_eaten >= philo->sim->meals_required)
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->full = true;
		pthread_mutex_unlock(&philo->meal_lock);
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->sim->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
	usleep((philo->sim->time_to_die - philo->sim->time_to_eat
			- philo->sim->time_to_sleep) / 5);
}
