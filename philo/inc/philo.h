/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:29:05 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/26 18:32:06 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

// every philo is a struct!
//

// 2 array : philo + forks
// fork = mutex; array of philo and array of mutex
//
//
typedef struct s_sim	t_sim;
typedef struct s_philo	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_sim
{
	long			philo_num;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_required;
	bool			end_simulation;
	pthread_t		monitor_thread;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_mutex_t	end_lock;
	pthread_mutex_t	print_lock;

}	t_sim;

typedef struct s_philo
{
	int					id;
	long				meals_eaten;
	long				last_meal_time;
	bool				full;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		meal_lock;
	pthread_t			thread_id;
	t_sim				*sim;
}	t_philo;

void	error_exit(char *error);
void	parse_input(int argc, char **argv, t_sim *sim);
long	get_time_ms(void);
bool	simulation_has_ended(t_sim *sim);
void	print_action(t_philo *philo, const char *action);
void	simulation_init(t_sim *sim);
void	*philo_routine(void *arg);
void	take_forks(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	*star_sim(t_sim *sim);
void	join_threads(t_sim *sim);
void	*monitor_simulation(void *arg);
void	check_philo_death(t_sim *sim);
void	check_all_full(t_sim *sim);
void	sim_clean(t_sim *sim);
int		ft_strlen(char *str);
int		is_num(char *str);
int		ft_isdigit(char i);
void	arg_parse(int argc, char **argv);
void	precise_sleep(long duration_ms);
void	struct_init(t_sim *sim, int i);
void	one_philo(t_philo *philo );

#endif
