/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:38:51 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/05 20:20:21 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	close_philo(t_phiolo *philo)
{
	monitoring_threads(philo);
	free_lst(philo->philosophers);
	return (0);
}

int	main(int argc, char **argv)
{
	t_phiolo	philo;

	if (argc != 5 && argc != 6)
	{
		printf("Error\n");
		return (0);
	}
	if (!create_var(&philo, argc, argv))
	{
		printf("Data isn't correct!\n");
		return (0);
	}
	create_lst(&philo);
	if (pthread_mutex_init(&philo.mutex, NULL) != 0)
		return (0);
	create_even_odd_threads(&philo, 1);
	create_even_odd_threads(&philo, 0);
	return (close_philo(&philo));
}
