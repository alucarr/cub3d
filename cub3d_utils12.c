/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils12.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:43 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:45 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture(t_data *data, int num)
{
	int	texy;

	set_rc_value(data);
	while (data->raycast->drawstart < data->raycast->drawend)
	{
		texy = (int)data->raycast->texpos & 63;
		data->raycast->texpos += data->raycast->texstep;
		if (data->raycast->side == 0 && data->raycast->raydirx > 0)
			data->cub3d->mlx_object_data[data->raycast->drawstart
				* data->cub3d->width + num] = data->objs->so_data[64 * texy
				+ data->raycast->tex_x];
		else if (data->raycast->side == 0 && data->raycast->raydirx < 0)
			data->cub3d->mlx_object_data[data->raycast->drawstart
				* data->cub3d->width + num] = data->objs->no_data[64 * texy
				+ data->raycast->tex_x];
		else if (data->raycast->side == 1 && data->raycast->raydiry > 0)
			data->cub3d->mlx_object_data[data->raycast->drawstart
				* data->cub3d->width + num] = data->objs->ea_data[64 * texy
				+ data->raycast->tex_x];
		else
			data->cub3d->mlx_object_data[data->raycast->drawstart
				* data->cub3d->width + num] = data->objs->we_data[64 * texy
				+ data->raycast->tex_x];
		data->raycast->drawstart++;
	}
}

void	set_rc_value(t_data *data)
{
	double	wallx;

	data->raycast->texnum = data->map[data->raycast->mapx][data->raycast->mapy]
		- 1;
	if (data->raycast->side == 0)
		wallx = data->raycast->posy + data->raycast->perpwalldist
			* data->raycast->raydiry;
	else
		wallx = data->raycast->posx + data->raycast->perpwalldist
			* data->raycast->raydirx;
	wallx -= floor(wallx);
	data->raycast->tex_x = (int)(wallx * (double)64);
	if (data->raycast->side == 0 && data->raycast->raydirx > 0)
		data->raycast->tex_x = 64 - data->raycast->tex_x - 1;
	if (data->raycast->side == 1 && data->raycast->raydiry < 0)
		data->raycast->tex_x = 64 - data->raycast->tex_x - 1;
	data->raycast->texstep = 1.0 * 64 / data->raycast->lineheight;
	data->raycast->texpos = (data->raycast->drawstart - 1080 / 2
			+ data->raycast->lineheight / 2) * data->raycast->texstep;
}

void	calculate_ray(t_data *data)
{
	if (data->raycast->side == 0)
		data->raycast->perpwalldist = data->raycast->sidedistx
			- data->raycast->deltadistx;
	else
		data->raycast->perpwalldist = data->raycast->sidedisty
			- data->raycast->deltadisty;
	data->raycast->lineheight = (int)(1080 / data->raycast->perpwalldist);
	data->raycast->drawstart = -data->raycast->lineheight / 2 + 1080 / 2;
	if (data->raycast->drawstart < 0)
		data->raycast->drawstart = 0;
	data->raycast->drawend = data->raycast->lineheight / 2 + 1080 / 2;
	if (data->raycast->drawend >= 1080)
		data->raycast->drawend = 1080 - 1;
}

int	is_true_value(t_data *data)
{
	if (data->ceil_flag == 1 && data->no_flag == 1 && data->ea_flag == 1
		&& data->we_flag == 1 && data->so_flag == 1 && data->floor_flag == 1)
		return (1);
	return (0);
}
