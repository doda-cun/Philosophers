/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:29:05 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/14 19:31:11 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdbool.h>
# include	<pthread.h>
# include	<sys/time.h>
# include	<limits.h>

// every philo is a struct!
//

// 2 array : philo + forks
// fork = mutex; array of philo and array of mutex
//
//


typedef struct	s_philo
{
	int	id;
	long		meals_eaten;
	long		last_meal_time;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		meal_lock;
	pthread_t	thread_id;
	t_sim		*sim;
}	t_philo;

typedef struct	s_fork
{
	pthread_mutex_t	fork;
	int 	fork_id;
}	t_fork;

typedef	struct s_sim
{
	long	philo_num;
	long	start_time;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_required;
	bool	end_simulation;
	pthread_mutex_t	*forks;
	t_philo	*philos;
	pthread_mutex_t	end_lock; //safely read/write end_simulation
	pthread_mutex_t	print_lock //??

}	t_sim;


void	error_exit(char *error);
void	parse_input(int argc, char **argv, t_sim *sim)

#endif
