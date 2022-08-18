/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:58:05 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/08 16:34:36 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	what_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_sleep(int time)
{
	long long int	start_time;

	start_time = what_time();
	while (what_time() - start_time < time)
		usleep(1);
	return ;
}
