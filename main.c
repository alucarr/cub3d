/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:36:02 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:36:02 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_data *data, t_cub3d *cub3d, t_objs *objs, t_raycast *raycast)
{
	data->objs = objs;
	data->cub3d = cub3d;
	data->raycast = raycast;
	init_tex(data);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_cub3d		*cub3d;
	t_objs		*objs;
	t_raycast	*raycast;

	if (ac == 2)
	{
		if (name_control(av[1]) && is_exist(av[1]))
		{
			data = malloc(sizeof(t_data));
			cub3d = malloc(sizeof(t_cub3d));
			objs = malloc(sizeof(t_objs));
			raycast = malloc(sizeof(t_raycast));
			if (!data || !cub3d || !objs || !raycast)
				return (0);
			init(data, cub3d, objs, raycast);
			get_file(av, data);
			get_direction(data, av);
			render(data);
		}
		else
			error_case("file error!");
	}
	else
		error_case("arguments error!");
}
