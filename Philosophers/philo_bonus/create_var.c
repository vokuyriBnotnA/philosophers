/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:54:36 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/08 16:21:46 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_var(t_phiolo *philo, int argc, char **argv)
{
	philo->start_time = what_time();
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
