/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:51:21 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/08 16:13:43 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	sem_unlink("/semaphores");
	sem_unlink("/sem_print");
	philo.semaphores = sem_open("/semaphores", O_CREAT | O_EXCL,
			0777, philo.number_of_philosophers);
	philo.sem_print = sem_open("/sem_print", O_CREAT | O_EXCL,
			0777, 1);
	if (philo.semaphores == SEM_FAILED || philo.sem_print == SEM_FAILED)
	{
		printf("Wrong semaphore!!\n");
		return (0);
	}
	create_pid(&philo);
	return (0);
}
