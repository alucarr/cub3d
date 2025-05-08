/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:24 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:26 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_fc_color(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->cub3d->width)
	{
		y = -1;
		while (++y < data->cub3d->height)
		{
			if (y < data->cub3d->height / 2)
				data->cub3d->mlx_object_data[y * data->cub3d->width
					+ x] = data->ceil_color;
			else
				data->cub3d->mlx_object_data[y * data->cub3d->width
					+ x] = data->floor_color;
		}
	}
}

void	render(t_data *data)
{
	data->cub3d->mlx_init = mlx_init();
	data->cub3d->mlx_window = mlx_new_window(data->cub3d->mlx_init,
			data->cub3d->width, data->cub3d->height, "CUB3D");
	data->cub3d->mlx_object = mlx_new_image(data->cub3d->mlx_init,
			data->cub3d->width, data->cub3d->height);
	data->cub3d->mlx_object_data
		= (int *)mlx_get_data_addr(data->cub3d->mlx_object,
			&data->cub3d->bits_per_pixel, &data->cub3d->size_line,
			&data->cub3d->endian);
	set_variables(data);
	mlx_loop_hook(data->cub3d->mlx_init, &render_loop, data);
	mlx_hook(data->cub3d->mlx_window, 2, 0, &press, data);
	mlx_hook(data->cub3d->mlx_window, 3, 0, &rele, data);
	mlx_hook(data->cub3d->mlx_window, 17, 1L << 17, &close_window, data);
	mlx_loop(data->cub3d->mlx_init);
}

void	set_variables(t_data *data)
{
	set_images(data);
	set_player_information(data);
	cam_options(data);
	control(data);
}

int	render_loop(t_data *data)
{
	clear_screen(data);
	set_fc_color(data);
	ray_caster(data);
	maneuver(data);
	return (0);
}

int	close_window(int key, void *data)
{
	(void)key;
	(void)data;
	exit(0);
}
