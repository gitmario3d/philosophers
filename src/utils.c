/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:29:56 by malena-b          #+#    #+#             */
/*   Updated: 2024/10/15 15:03:05 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_error_msg(t_info *info, char *error_msg)
{
	printf("Error, %s\n", error_msg);
	info->error_check = 1;
	return (-1);
}

void	ft_free_all(t_info *info)
{
	if (info->philos || info->forks)
	{
		if (info->forks)
			free(info->forks);
		if (info->philos)
			free(info->philos);
		free(info);
	}
}

int	ft_get_time(void)
{
	struct timeval	time_val;

	gettimeofday(&time_val, NULL);
	return (time_val.tv_sec * 1000 + time_val.tv_usec / 1000);
}

int	ft_get_mutex_int(t_info *info, t_philo *philo, int on_off)
{
	int	aux;

	if (!on_off)
	{
		ft_mutex_actions(info, LOCK, &info->dead_lock);
		aux = info->dead_flag;
		ft_mutex_actions(info, UNLOCK, &info->dead_lock);
	}
	else if (on_off)
	{
		ft_mutex_actions(info, LOCK, &info->meat_lock);
		aux = philo->last_meat;
		ft_mutex_actions(info, UNLOCK, &info->meat_lock);
	}
	return (aux);
}
