/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_smth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:52:36 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/30 16:07:47 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	char_to_int(char *num)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (!num)
		return (0);
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9' || num[0] == '0')
			return (0);
		result *= 10;
		result += num[i] - '0';
		if (result > __INT32_MAX__)
			return (0);
		i++;
	}
	return (result);
}

long long int	char_to_ull(char *num)
{
	int						i;
	unsigned long long int	result;

	i = 0;
	result = 0;
	if (!num)
		return (0);
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9' || num[0] == '0')
			return (0);
		result *= 10;
		result += num[i] - '0';
		if (result > 9223372036854775807)
			return (0);
		i++;
	}
	return (result);
}
