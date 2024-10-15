/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_codes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:07:05 by malena-b          #+#    #+#             */
/*   Updated: 2024/10/15 15:06:10 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_report(t_philo *philo, t_lock action)
{
	int	actual_time;

	actual_time = ft_get_time() - philo->info->start_time;
	if (ft_get_mutex_int(philo->info, philo, 0))
		return ;
	ft_mutex_actions(philo->info, LOCK, philo->write_lock);
	if (action == L_FORK)
		printf("%d %d has taken a fork\n", actual_time, philo->id);
	else if (action == R_FORK)
		printf("%d %d has taken a fork\n", actual_time, philo->id);
	else if (action == THINK)
		printf("%d %d is thinking\n", actual_time, philo->id);
	else if (action == EAT)
		printf("%d %d is eating\n", actual_time, philo->id);
	else if (action == SLEEP)
		printf("%d %d is sleeping\n", actual_time, philo->id);
	else if (action == DIED)
		printf("%d %d died\n", actual_time, philo->id);
	ft_mutex_actions(philo->info, UNLOCK, philo->write_lock);
}

void	ft_sleep(int sleep_time)
{
	int	start_time;

	start_time = ft_get_time();
	while ((ft_get_time() - start_time) < sleep_time)
		usleep(10);
}

void	*ft_dinner(void *aux)
{
	t_philo	*philo;

	philo = (t_philo *) aux;
	if (!(philo->id % 2))
		ft_sleep(50);
	while (!ft_get_mutex_int(philo->info, philo, 0) && !philo->full)
	{
		ft_forks_mutex(philo, 1);
		ft_report(philo, EAT);
		ft_monitor_mutex(philo->info, MEALS, philo, 0);
		ft_sleep(philo->info->time_to_eat);
		ft_forks_mutex(philo, 0);
		ft_report(philo, SLEEP);
		ft_sleep(philo->info->time_to_sleep);
		ft_report(philo, THINK);
	}
	return (NULL);
}