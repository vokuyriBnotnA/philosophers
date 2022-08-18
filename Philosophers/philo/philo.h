/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:01:51 by klemongr          #+#    #+#             */
/*   Updated: 2022/04/05 20:20:27 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philosophers
{
	int						phiolo_id;
	pthread_t				philo_thread;
	pthread_mutex_t			mutex;
	int						philo_eat;
	long long int			hunger_time;
	struct s_philosophers	*next;
	struct s_philosophers	*prev;

}	t_philosophers;

typedef struct s_philo
{
	int				number_of_philosophers;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long int	start_time;
	t_philosophers	*philosophers;
	pthread_mutex_t	mutex;

}	t_phiolo;

t_philosophers	*init(int phiolo_id);
t_philosophers	*addelem(t_philosophers *lst,
					int phiolo_id, pthread_t philo);
void			*philosopher(void *args);
long long int	what_time(void);
void			ft_sleep(int time);
int				char_to_int(char *num);
long long int	char_to_ull(char *num);
int				create_var(t_phiolo *philo, int argc, char **argv);
void			create_lst(t_phiolo *philo);
void			create_even_odd_threads(t_phiolo *philo, int even);
int				monitoring_threads(t_phiolo *philo);
void			wait_threads_distroy_mutex(t_phiolo *philo);
void			free_lst(t_philosophers *lst);

#endif
