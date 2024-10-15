/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:21:07 by malena-b          #+#    #+#             */
/*   Updated: 2024/10/15 16:53:30 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_init_mutex(t_info *info)
{
	int 	i;
	t_fork	*fork;

	i = 0;
	ft_mutex_actions(info, INIT, &info->dead_lock);
	ft_mutex_actions(info, INIT, &info->meat_lock);
	ft_mutex_actions(info, INIT, &info->write_lock);
	info->forks = malloc(sizeof(t_fork) * info->philo_numbers);
	if (!info->forks)
		printf("error");
	while (i < info->philo_numbers)
	{
		fork = info->forks + i;
		ft_mutex_actions(info, INIT, &fork->fork);
		fork->id = i + 1;
		i++;
	}
	
}

void	ft_init_philos(t_info *info)
{
	int		i;
	t_philo	*philo;

	VER SI CAMBIANDO LOS PHILOS A UNA LISTA ENLAZADA SE ARREGLA EL SEGFAULT
	i = 0;
	while (!info->error_check && i < info->philo_numbers)
	{
		philo = info->philos + i;
		philo->id = i + 1;
		philo->info = info;
		philo->meats = 0;
		philo->full = 0;
		philo->dead_flag = &info->dead_flag;
		philo->dead_lock = &info->dead_lock;
		philo->meat_lock = &info->meat_lock;
		philo->write_lock = &info->write_lock;
		philo->last_meat = 0;
		philo->r_fork = &info->forks[i];
		philo->l_fork = &info->forks[(i + 1) % info->philo_numbers];
		i++;
	}
}

t_info	*ft_init_info(t_info *info, char **argv)
{
	info = malloc(sizeof(t_info *));
	if (!info)
		ft_error_msg(NULL, "info malloc went wrong.");
	info->error_check = 0;
	info->philo_numbers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (!argv[5])
		info->total_meals = -9;
	else
		info->total_meals = ft_atoi(argv[5]);
	if (!info->error_check && info->total_meals == 0)
		info->error_check = 1;
	info->philos = malloc(sizeof(t_philo) * (info->philo_numbers + 1));
	if (!info->philos)
		ft_error_msg(NULL, "creation of malloc failed.");
	return (info);
}

void	ft_init_thread(t_info *info, int i)
{
	t_philo	*aux;

	if (info->error_check)
		return ;
	info->start_time = ft_get_time();
	aux = info->philos;
	while (!info->error_check && i < info->philo_numbers)
	{
		ft_thread(CREATE, ft_dinner, aux, 0);
		i++;
		aux = info->philos + i;
	}
	ft_thread(CREATE, ft_monitor, info, 1);
	i = 0;
	while (i < info->philo_numbers)
	{
		aux = info->philos + i;
		ft_thread(JOIN, NULL, aux, 0);
		i++;
	}
	ft_thread(JOIN, NULL, info, 1);
	ft_clean_mutex(info);
}
