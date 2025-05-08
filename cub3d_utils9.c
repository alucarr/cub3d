/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils9.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:29 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:31 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_screen(t_data *data)
{
	mlx_destroy_image(data->cub3d->mlx_init, data->cub3d->mlx_object);
	data->cub3d->mlx_object = mlx_new_image(data->cub3d->mlx_init,
			data->cub3d->width, data->cub3d->height);
	data->cub3d->mlx_object_data
		= (int *)mlx_get_data_addr(data->cub3d->mlx_object,
			&data->cub3d->bits_per_pixel, &data->cub3d->size_line,
			&data->cub3d->endian);
}

void	ray_caster(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->cub3d->width)
	{
		data->raycast->camerax = 2 * x / (double)data->cub3d->width - 1;
		data->raycast->raydirx = data->raycast->dirx + data->raycast->planex
			* data->raycast->camerax;
		data->raycast->raydiry = data->raycast->diry + data->raycast->planey
			* data->raycast->camerax;
		data->raycast->mapx = (int)data->raycast->posx;
		data->raycast->mapy = (int)data->raycast->posy;
		if (data->raycast->raydirx == 0)
			data->raycast->deltadistx = 1e30;
		else
			data->raycast->deltadistx = fabs(1 / data->raycast->raydirx);
		if (data->raycast->raydiry == 0)
			data->raycast->deltadisty = 1e30;
		else
			data->raycast->deltadisty = fabs(1 / data->raycast->raydiry);
		calculate_all_rc(data, x);
		x++;
	}
	mlx_put_image_to_window(data->cub3d->mlx_init, data->cub3d->mlx_window,
		data->cub3d->mlx_object, 0, 0);
}

void	calculate_all_rc(t_data *data, int n)
{
	nswe(data);
	wall(data);
	calculate_ray(data);
	texture(data, n);
}

void	nswe(t_data *data)
{
	if (data->raycast->raydirx < 0)
	{
		data->raycast->stepx = -1;
		data->raycast->sidedistx = (data->raycast->posx - data->raycast->mapx)
			* data->raycast->deltadistx;
	}
	else
	{
		data->raycast->stepx = 1;
		data->raycast->sidedistx = (data->raycast->mapx + 1.0
				- data->raycast->posx) * data->raycast->deltadistx;
	}
	if (data->raycast->raydiry < 0)
	{
		data->raycast->stepy = -1;
		data->raycast->sidedisty = (data->raycast->posy - data->raycast->mapy)
			* data->raycast->deltadisty;
	}
	else
	{
		data->raycast->stepy = 1;
		data->raycast->sidedisty = (data->raycast->mapy + 1.0
				- data->raycast->posy) * data->raycast->deltadisty;
	}
}

void	wall(t_data *data)
{
	data->raycast->wall = 0;
	while (!data->raycast->wall)
	{
		if (data->raycast->sidedistx < data->raycast->sidedisty)
		{
			data->raycast->sidedistx += data->raycast->deltadistx;
			data->raycast->mapx += data->raycast->stepx;
			data->raycast->side = 0;
		}
		else
		{
			data->raycast->sidedisty += data->raycast->deltadisty;
			data->raycast->mapy += data->raycast->stepy;
			data->raycast->side = 1;
		}
		if (data->map[data->raycast->mapx][data->raycast->mapy] == '1')
			data->raycast->wall = 1;
	}
}
