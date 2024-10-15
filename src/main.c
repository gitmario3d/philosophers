/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:09:44 by malena-b          #+#    #+#             */
/*   Updated: 2024/10/15 15:24:42 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_check_args(char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		ft_error_msg(NULL, "invalid number of philosophers");
	if (ft_atoi(argv[5]) && ft_atoi(argv[5]) <= 0)
		ft_error_msg(NULL, "invalid number of meals.");
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc > 6 || argc < 5)
	{
		ft_error_msg(NULL, "invalid number of arguments");
		return (2);
	}
	ft_check_args(argv);
	info = NULL;
	info = ft_init_info(info, argv);
	ft_init_philos(info);
	if (!info->error_check && !ft_check_philo_numbers(info))
	{
		ft_thread(JOIN, info->philos, NULL, 0);
		ft_clean_mutex(info);
		ft_free_all(info);
		return (0);
	}
	ft_init_thread(info, 0);
	ft_free_all(info);
	return (0);
}
