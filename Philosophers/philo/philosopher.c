/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:20:42 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/06 20:36:29 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_local_philo
{
	int				id;
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	long long int	*time;
	long long int	start_time;
	long long int	time_to_die;
	int				*eat;

}	t_local_philo;

void	create_local_var(t_phiolo *philo, t_local_philo *local)
{
	pthread_mutex_lock(&philo->mutex);
	local->id = philo->philosophers->phiolo_id;
	local->mutex_right = &philo->philosophers->mutex;
	local->mutex_left = &philo->philosophers->prev->mutex;
	local->time = &philo->philosophers->hunger_time;
	*local->time = what_time();
	local->eat = &philo->philosophers->philo_eat;
	philo->philosophers->hunger_time = what_time();
	local->start_time = philo->start_time;
	local->time_to_die = philo->time_to_die;
	pthread_mutex_unlock(&philo->mutex);
}

void	*philosopher(void *args)
{
	t_phiolo		*philo;
	t_local_philo	local;

	philo = (t_phiolo *) args;
	create_local_var(philo, &local);
	while (philo->number_of_philosophers != 1)
	{
		pthread_mutex_lock(local.mutex_right);
		pthread_mutex_lock(local.mutex_left);
		printf("%lld %d has taken a fork\n", what_time() - local.start_time,
			local.id);
		printf("%lld %d is eating\n", what_time() - local.start_time, local.id);
		local.eat[0]++;
		*local.time = what_time();
		ft_sleep(philo->time_to_eat * 10);
		pthread_mutex_unlock(local.mutex_right);
		pthread_mutex_unlock(local.mutex_left);
		printf("%lld %d is sleeping\n", what_time() - local.start_time,
			local.id);
		ft_sleep(philo->time_to_sleep * 10);
		printf("%lld %d is thinking\n", what_time() - local.start_time,
			local.id);
	}
	return (NULL);
}
