/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_phil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:21:07 by malena-b          #+#    #+#             */
/*   Updated: 2024/09/26 12:20:33 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_init_mutex(t_info *info)
{
	
}

void	ft_init_philos(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = 1;
	while (i <= info->philo_numbers)
	{
		philo = info->philos + (i - 1);
		philo->id = i++;
	}
}

t_info	*ft_init_info(t_info *info, char **argv)
{
	info = malloc(sizeof(t_info *));
	if (!info)
		ft_error_exit("info malloc went wrong.", info);
	info->philo_numbers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (!argv[5])
		info->total_meals = -1;
	else
		info->total_meals = argv[5];
	info->philos = malloc(sizeof(t_philo *) * (info->philo_numbers + 1));
	if (!info->philos)
		ft_error_exit("creation of malloc failed.", info);
	return (info);
}
