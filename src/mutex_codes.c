/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:35:03 by malena-b          #+#    #+#             */
/*   Updated: 2024/10/15 16:50:15 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_m_error_check(t_m_code m_code, t_info *info, int e_code)
{
	if (e_code == 0)
		return;
	if (e_code == EINVAL && (m_code == DESTROY || m_code == LOCK))
		ft_error_msg(info, "Not a valid mutex.");
	if (e_code == EBUSY && m_code == DESTROY)
		ft_error_msg(info, "The implementation has detected an " \
		"attempt to destroy the object referenced by mutex while " \
		"it is locked or referenced (for example, while being used " \
		"by another thread.");
	if (e_code == EAGAIN)
		ft_error_msg(info, "The system lacked the necessary resources.");
	if (e_code == EDEADLK)
		ft_error_msg(info, "The current thread already owns the mutex.");
	if (e_code == EPERM && m_code == UNLOCK)
		ft_error_msg(info, "The current thread does not own the mutex.");
}

void	ft_mutex_actions(t_info	*info, t_m_code m_code, pthread_mutex_t *mutex)
{
	if (m_code == INIT)
		ft_m_error_check(m_code, info, pthread_mutex_init(mutex, NULL));
	if (m_code == LOCK)
		ft_m_error_check(m_code, info, pthread_mutex_lock(mutex));
	if (m_code == UNLOCK)
		ft_m_error_check(m_code, info, pthread_mutex_unlock(mutex));
	if (m_code == DESTROY)
		ft_m_error_check(m_code, info, pthread_mutex_destroy(mutex));
}


void	ft_forks_mutex(t_philo *philo, int option)
{
	if (option)
	{
		if (philo->id % 2)
		{
			ft_mutex_actions(philo->info, LOCK, &philo->r_fork->fork);
			ft_report(philo, R_FORK);
			ft_mutex_actions(philo->info, LOCK, &philo->l_fork->fork);
			ft_report(philo, L_FORK);
		}
		else
		{
			ft_mutex_actions(philo->info, LOCK, &philo->l_fork->fork);
			ft_report(philo, L_FORK);
			ft_mutex_actions(philo->info, LOCK, &philo->r_fork->fork);
			ft_report(philo, R_FORK);
		}
	}
	else
	{
		ft_mutex_actions(philo->info, UNLOCK, &philo->r_fork->fork);
		ft_mutex_actions(philo->info, UNLOCK, &philo->l_fork->fork);
	}
}

void	ft_monitor_mutex(t_info *info, t_lock m_code, t_philo *philo, int opt)
{
	if (m_code == DEATH)
	{
		ft_mutex_actions(info, LOCK, &info->dead_lock);
		info->dead_flag = 1;
		ft_mutex_actions(info, UNLOCK, &info->dead_lock);
	}
	if (m_code == MEALS && opt)
	{
		ft_mutex_actions(info, LOCK, &info->meat_lock);
		if (philo->meats == info->total_meals)
		{
			info->full++;
			philo->full = 1;
			philo->meats = 0;
		}
		ft_mutex_actions(info, UNLOCK, &info->meat_lock);
	}
	else if (m_code == MEALS && !opt)
	{
		ft_mutex_actions(info, LOCK, philo->meat_lock);
		philo->last_meat = ft_get_time() - philo->info->start_time;
		philo->meats++;
		ft_mutex_actions(info, UNLOCK, philo->meat_lock);
	}
}

void	ft_clean_mutex(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < info->philo_numbers)
	{
		philo = info->philos + i;
		ft_mutex_actions(info, DESTROY, &philo->r_fork->fork);
		printf("Aquí llega!\n");
		i++;
	}
	ft_mutex_actions(info, DESTROY, &info->dead_lock);
	ft_mutex_actions(info, DESTROY, &info->write_lock);
	ft_mutex_actions(info, DESTROY, &info->meat_lock);
}
