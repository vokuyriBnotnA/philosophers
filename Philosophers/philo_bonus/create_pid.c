/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:59:32 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/09 15:57:39 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_pid(int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		waitpid(0, NULL, 0);
		i++;
	}
	return ;
}

void	create_pid(t_phiolo *philo)
{
	int	*pid;
	int	i;

	pid = malloc(philo->number_of_philosophers + 1 * sizeof(int));
	if (!pid)
		return ;
	i = 0;
	philo->start_time = what_time();
	while (i < philo->number_of_philosophers)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			philosopher(i + 1, philo);
			exit (0);
		}
		i++;
	}
	wait_all_pid(philo->number_of_philosophers);
	free (pid);
	return ;
}
