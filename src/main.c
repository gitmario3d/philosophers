/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:09:44 by malena-b          #+#    #+#             */
/*   Updated: 2024/09/13 13:56:20 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	
	if (argc > 5 | argc < 4)
		error_exit("invalid number of arguments");
	//Añadir esto a una función de inicializar la t_info
	info->time_to_die = ft_atoi(argv[1]);
	info->time_to_eat = ft_atoi(argv[2]);
	info->time_to_sleep = ft_atoi(argv[3]);
	//Añadir esto a función nueva check_args y terminar de comprobar los args
	if (info->philo_numbers <= 0 | info->philo_numbers > 200)
		error_exit("invalid number of philosophers");
	return (0);
}
