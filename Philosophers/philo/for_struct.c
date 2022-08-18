/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 01:02:28 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/05 19:55:27 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int time)
{
	long long int	start_time;

	time /= 10;
	start_time = what_time();
	while (what_time() - start_time < time)
		usleep(100);
	return ;
}

long long int	what_time(void)
{
	int				time;
	struct timeval	t;
	long long int	tm;

	time = gettimeofday(&t, NULL);
	tm = t.tv_sec * 1000;
	tm += t.tv_usec / 1000;
	return (tm);
}

t_philosophers	*init(int phiolo_id)
{
	t_philosophers	*lst;

	lst = (t_philosophers *) malloc(sizeof(t_philosophers));
	if (!lst)
		return (NULL);
	lst->phiolo_id = phiolo_id;
	lst->next = lst;
	lst->prev = lst;
	return (lst);
}

t_philosophers	*addelem(t_philosophers *lst, int phiolo_id, pthread_t philo)
{
	t_philosophers	*temp;
	t_philosophers	*p;

	temp = (t_philosophers *) malloc(sizeof(t_philosophers));
	if (!temp)
		return (NULL);
	p = lst->next;
	lst->next = temp;
	if (pthread_mutex_init(&temp->mutex, NULL) != 0)
		return (NULL);
	temp->hunger_time = 0;
	temp->phiolo_id = phiolo_id;
	temp->philo_thread = philo;
	temp->philo_eat = 0;
	temp->next = p;
	temp->prev = lst;
	p->prev = temp;
	return (temp);
}

void	free_lst(t_philosophers *lst)
{
	t_philosophers	*start;

	start = lst;
	lst = lst->next;
	while (start != lst)
	{
		free(lst);
		lst = lst->next;
	}
	return ;
}
