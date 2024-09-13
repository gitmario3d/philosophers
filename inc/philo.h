/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:00:18 by malena-b          #+#    #+#             */
/*   Updated: 2024/09/13 13:51:00 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_philo
{
	pthread_t	thread;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
}				t_philo;

typedef struct s_info
{
	int				philo_numbers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				total_meals;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}				t_info;

int		ft_atoi(const char *str);
void	error_exit(char	*error_msg);
