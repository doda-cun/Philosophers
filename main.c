/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:27:52 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/14 19:24:55 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// ./philo 5 800 200 200 [6]
int main(int argc, char **argv)
{
	t_sim	sim;

	if (argc == 5 || argc == 6)
	{
		parse_input(argc, argv, &sim);
		simulation_init(&sim);
		start_dinner(&sim);
		clean_simu(sim);

	}
	else
	{
		error_exit("Wrong Input\n");
	}
}
