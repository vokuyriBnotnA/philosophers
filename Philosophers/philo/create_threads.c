/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:53:32 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/05 20:21:39 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_var(t_phiolo *philo, int argc, char **argv)
{
	philo->number_of_philosophers = char_to_int(argv[1]);
	philo->time_to_die = char_to_ull(argv[2]);
	philo->time_to_eat = char_to_ull(argv[3]);
	philo->time_to_sleep = char_to_ull(argv[4]);
	philo->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = char_to_int(argv[5]);
	if (!philo->number_of_philosophers || !philo->time_to_die
		|| !philo->time_to_eat || !philo->time_to_sleep
		|| !philo->number_of_times_each_philosopher_must_eat)
		return (0);
	return (1);
}

void	create_lst(t_phiolo *philo)
{
	int	i;

	philo->philosophers = init(1);
	i = 2;
	while (i <= philo->number_of_philosophers)
	{
		philo->philosophers = addelem(philo->philosophers, i, NULL);
		if (!philo->philosophers)
			return ;
		i++;
	}
	philo->philosophers = philo->philosophers->next;
	return ;
}

void	create_even_odd_threads(t_phiolo *philo, int even)
{
	int	i;

	i = 1;
	philo->start_time = what_time();
	while (i <= philo->number_of_philosophers)
	{
		if ((i % 2 == 0 && even) || (i % 2 != 0 && !even))
		{
			if (pthread_create(&philo->philosophers->philo_thread,
					NULL, philosopher, philo) != 0)
				return ;
			usleep(100);
		}
		philo->philosophers = philo->philosophers->next;
		i++;
	}
	return ;
}
