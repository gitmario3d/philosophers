/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_codes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:52:10 by malena-b          #+#    #+#             */
/*   Updated: 2024/10/15 16:33:10 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_threads_errorcheck(t_m_code code, t_info *info, int e_code)
{
	if (e_code == 0)
		return;
	if (e_code == EAGAIN)
		ft_error_msg(info, "Insufficient resources to " \
		"create another thread.");
	else if (e_code == EINVAL)
		ft_error_msg(info, "Invalid settings in attr.");
	else if (e_code == EPERM)
		ft_error_msg(info, "No permission to set the scheduling " \
		"policy and parameters specified in attr.");
	else if (e_code == EDEADLK && code == JOIN)
		ft_error_msg(info, "A deadlock was detected or the value " \
		"of thread specifies the calling thread.");
	else if (e_code == ESRCH && code == JOIN)
		ft_error_msg(info, "No thread could be found corresponding " \
		"to that specified by the given thread ID.");
}

/* void	ft_thread(t_m_code thr_code, void *aux, void *(*func)(void *), int monitor)
{
	t_philo	*philo;
	t_info	*info;

	printf("Aquí llega!\n");
	if (monitor)
	{
		info = (t_info *)aux;
		if (thr_code == CREATE)
			ft_threads_errorcheck(thr_code, info, \
			pthread_create(&info->monitor, NULL, func, (void *)info));
		else if (thr_code == JOIN)
			ft_threads_errorcheck(thr_code, info, pthread_join(info->monitor, NULL));
	}
	else
	{
		philo = (t_philo *)aux;
		if (thr_code == CREATE)
			ft_threads_errorcheck(thr_code, philo->info, \
			pthread_create(&philo->thread, NULL, func, (void *)philo));
		else if (thr_code == JOIN)
			ft_threads_errorcheck(thr_code, philo->info, \
			pthread_join(philo->thread, NULL));
	}
} */

void	ft_thread(t_m_code code, void *(*func)(void *), void *aux, int monitor)
{
	t_info	*info;
	t_philo	*philo;

	if (monitor)
	{
		info = (t_info *)aux;
		if (code == CREATE)
			ft_threads_errorcheck(code, info, \
			pthread_create(&info->monitor, NULL, func, (void *)info));
		else if (code == JOIN)
			ft_threads_errorcheck(code, info, pthread_join(info->monitor, NULL));
	}
	else
	{
		philo = (t_philo *)aux;
		if (code == CREATE)
			ft_threads_errorcheck(code, philo->info, \
			pthread_create(&philo->thread, NULL, func, (void *)philo));
		else if (code == JOIN)
			ft_threads_errorcheck(code, philo->info, \
			pthread_join(philo->thread, NULL));
	}
}