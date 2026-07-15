/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:27:52 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/26 17:27:28 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// ./philo 5 800 200 200 [6]

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (argc == 5 || argc == 6)
	{
		parse_input(argc, argv, &sim);
		simulation_init(&sim);
		star_sim(&sim);
		join_threads(&sim);
		sim_clean(&sim);
	}
	else
		error_exit("Program needs 5 or 6 inputs to run.");
	return (EXIT_SUCCESS);
}
