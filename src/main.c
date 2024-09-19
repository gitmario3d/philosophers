/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:09:44 by malena-b          #+#    #+#             */
/*   Updated: 2024/09/17 12:03:17 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_check_args(char **argv)
{
	if (argv[1] <= 0 | argv[1] > 200)
		error_exit("invalid number of philosophers", NULL);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc > 5 | argc < 4)
		ft_error_exit("invalid number of arguments", NULL);
	ft_check_args(argv);
	ft_init_info(info, argv);
	return (0);
}
