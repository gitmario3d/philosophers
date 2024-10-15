/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_codes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:42:17 by malena-b          #+#    #+#             */
/*   Updated: 2024/10/15 14:49:33 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_monitor(void *aux)
{
	t_info	*info;
	t_philo	*philo;
	int		start;
	int		i;

	info = (t_info *) aux;
	while (!ft_get_mutex_int(info, philo, 0))
	{
		i = -1;
		while (++i < info->philo_numbers && !ft_get_mutex_int(info, philo, 0))
		{
			philo = info->philos + i;
			ft_monitor_mutex(info, MEALS, philo, 1);
			start = ft_get_time() - info->start_time;
			if ((start - ft_get_mutex_int(info, philo, 1)) \
				> info->time_to_die)
			{
				ft_report(philo, DIED);
				ft_monitor_mutex(info, DEATH, philo, 0);
			}
			if (info->full == info->philo_numbers)
				ft_monitor_mutex(info, DEATH, philo, 0);
		}
	}
	return (NULL);
}