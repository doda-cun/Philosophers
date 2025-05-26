/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:48:10 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/26 18:21:25 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_pos_num(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
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
	arg_parse(argc, argv);
	sim->philo_num = ft_pos_atol(argv[1]);
	sim->time_to_die = ft_pos_atol(argv[2]);
	sim->time_to_eat = ft_pos_atol(argv[3]);
	sim->time_to_sleep = ft_pos_atol(argv[4]);
	if (argc == 6)
		sim->meals_required = ft_pos_atol(argv[5]);
	else
		sim->meals_required = -1;
}

void	arg_parse(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			error_exit("Empty arg not allowed\n.");
		if (!is_pos_num(argv[i]))
			error_exit("Error: only numeric arg allowed\n");
		if (ft_strlen(argv[i]) > 10 || ft_pos_atol(argv[i]) > INT_MAX)
			error_exit("Error:number too large\n");
		i++;
	}
}
