/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:03:10 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/26 08:40:38 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data		data;
	size_t		i;

	if (check_is_heredoc(ac, av, &data))
		return (1);
	data.is_heredoc = 0;
	if (check_error_bonus(ac, av, env, &data))
		return (1);
	if (struct_attribution(ac, av, env, &data))
		return (1);
	if (pi_opening(&data))
		return (1);
	i = 0;
	while (i < data.ac)
	{
		run_execution(av, &data, i);
		i++;
	}
	closing_pipes(&data, -1);
	close(data.in_fd);
	close(data.out_fd);
	wait_for_pid(&data);
	free_all_struct(&data);
	return (0);
}
