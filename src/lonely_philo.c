/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:31:36 by malena-b          #+#    #+#             */
/*   Updated: 2024/10/15 14:45:55 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_one_dinner(void *aux)
{
	t_philo	*philo;

	philo = (t_philo *)aux;
	ft_mutex_actions(philo->info, LOCK, &philo->r_fork->fork);
	ft_report(philo, R_FORK);
	ft_mutex_actions(philo->info, UNLOCK, &philo->r_fork->fork);
	ft_sleep(philo->info->time_to_die);
	ft_report(philo, DIED);
	return (NULL);
}

int	ft_check_philo_numbers(t_info *info)
{
	info->start_time = ft_get_time();
	if (info->philo_numbers == 1)
		ft_thread(CREATE, info->philos, ft_one_dinner, 0);
	else
		return (1);
	return (0);
}
