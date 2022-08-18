/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:04:14 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/09 15:58:02 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_local
{
	int				id;
	long long int	time_to_die;
	long long int	*eat_time;
	long long int	*sem_time;
	long long int	*start_time;
	sem_t			*sem_print;

}	t_local;

typedef struct s_for_monitoring
{
	long long int	sem_time_local;
	t_local			for_monitor;
	pthread_t		monitor;
	pthread_t		monitor_2;

}	t_for_moniroting;

void	*monitoring_2(void *args)
{
	t_local	*local;

	local = (t_local *) args;
	while (1)
	{
		if (what_time() - local->sem_time[0] >= 500)
			exit (0);
	}
	return (NULL);
}

void	*monitoring(void *args)
{
	t_local	*local;

	local = (t_local *) args;
	while (1)
	{
		local->sem_time[0] = what_time();
		if (what_time() - local->eat_time[0] >= local->time_to_die)
		{
			sem_wait(local->sem_print);
			printf("%lld %d died\n", what_time() - local->start_time[0],
				local->id);
			exit (0);
		}
	}
	return (NULL);
}

void	print_message(sem_t *sem, int id, long long int start_time,
		char *message)
{
	long long int	t;

	t = what_time() - start_time;
	sem_wait(sem);
	printf("%lld %d %s\n", t, id, message);
	sem_post(sem);
	return ;
}

void	life_cycle(t_phiolo *philo, int id, long long int *eat_time_local,
		int eat_count)
{
	while (1)
	{
		sem_wait(philo->semaphores);
		print_message(philo->sem_print, id, philo->start_time,
			"has taken a fork");
		sem_wait(philo->semaphores);
		print_message(philo->sem_print, id, philo->start_time,
			"has taken a fork");
		print_message(philo->sem_print, id, philo->start_time, "is eating");
		*eat_time_local = what_time();
		eat_count++;
		ft_sleep(philo->time_to_eat);
		sem_post(philo->semaphores);
		sem_post(philo->semaphores);
		print_message(philo->sem_print, id, philo->start_time, "is sleeping");
		ft_sleep(philo->time_to_sleep);
		print_message(philo->sem_print, id, philo->start_time, "is thinking");
		if (eat_count == philo->number_of_times_each_philosopher_must_eat)
			exit (0);
	}
	return ;
}

void	philosopher(int id, t_phiolo *philo)
{
	int					eat_count;
	long long int		eat_time_local;
	t_for_moniroting	local;

	eat_count = 0;
	eat_time_local = philo->start_time;
	local.for_monitor.id = id;
	local.for_monitor.sem_print = philo->sem_print;
	local.for_monitor.time_to_die = philo->time_to_die;
	local.sem_time_local = philo->start_time;
	local.for_monitor.sem_time = &local.sem_time_local;
	local.for_monitor.eat_time = &eat_time_local;
	local.for_monitor.start_time = &philo->start_time;
	pthread_create(&local.monitor, NULL, monitoring, &local.for_monitor);
	pthread_create(&local.monitor_2, NULL, monitoring_2, &local.for_monitor);
	life_cycle(philo, id, &eat_time_local, eat_count);
	exit (0);
}
