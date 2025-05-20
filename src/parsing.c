/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:48:10 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/20 18:42:53 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"


static int	is_pos_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long int	ft_pos_atol(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	parse_input(int argc, char **argv, t_sim *sim)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		error_exit("Wrong input");
	if ((!is_pos_num(argv[1])) || !is_pos_num(argv[2]) || !is_pos_num(argv[3])
		||!is_pos_num(argv[4]) || (argc == 6 && !is_pos_num(argv[5])))
		error_exit ("Error: Arguments must be positive integers\n.");
	sim->philo_num = ft_pos_atol(argv[1]);
	sim->time_to_die = ft_pos_atol(argv[2]);
	sim->time_to_eat = ft_pos_atol(argv[3]);
	sim->time_to_sleep = ft_pos_atol(argv[4]);
	if (argc == 6)
		sim->meals_required = ft_pos_atol(argv[5]);
	else
		sim->meals_required = -1;
}
