/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:54:25 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/05 19:29:00 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitoring_threads(t_phiolo *philo)
{
	int	eat_time;
	int	i;

	while (1)
	{
		i = 0;
		eat_time = 0;
		while (i < philo->number_of_philosophers)
		{
			if (philo->philosophers->philo_eat
				== philo->number_of_times_each_philosopher_must_eat)
				eat_time++;
			if (what_time() - philo->philosophers->hunger_time
				>= philo->time_to_die)
			{
				printf("%lld %d died\n", what_time() - philo->start_time,
					philo->philosophers->phiolo_id);
				return (0);
			}
			philo->philosophers = philo->philosophers->next;
			i++;
		}
		if (eat_time + 1 == philo->number_of_philosophers && eat_time != 0)
			return (0);
	}
}

void	wait_threads_distroy_mutex(t_phiolo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		pthread_join(philo->philosophers->philo_thread, NULL);
		pthread_mutex_destroy(&philo->philosophers->mutex);
		philo->philosophers = philo->philosophers->next;
		i++;
	}
	pthread_mutex_destroy(&philo->mutex);
}
