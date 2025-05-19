/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:06:39 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/19 17:50:17 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	t_sim	*sim = philo->sim;
//little delay for even numbers to avoid deadlock
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!simulation_has_ended(sim))
	{
		take_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
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
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	print_action(philo, "is eating");
	usleep(philo->sim->time_to_eat * 1000);
	philo->meals_eaten++;
	if (philo->sim->meals_required > 0
		&& philo->meals_eaten >= philo->sim->meals_required)
		philo->full = true;
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
}
