/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:01:51 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/08 16:19:48 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				number_of_philosophers;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long int	start_time;
	sem_t			*semaphores;
	sem_t			*sem_print;

}	t_phiolo;

int				create_var(t_phiolo *philo, int argc, char **argv);
void			ft_sleep(int time);
long long int	what_time(void);
void			create_pid(t_phiolo *philo);
int				char_to_int(char *num);
long long int	char_to_ull(char *num);
void			philosopher(int id, t_phiolo *philo);

#endif
