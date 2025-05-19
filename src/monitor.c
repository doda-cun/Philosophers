/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:12:35 by doda-cun          #+#    #+#             */
/*   Updated: 2025/05/15 19:16:04 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_routine(void *arg)
{
	t_sim *sim = (t_sim *)arg;
	int i;

	while (!simulation_has_ended(sim))
	{
		i = 0;
		while (i < sim->philo_num)
		{
			
		}
	}
}
