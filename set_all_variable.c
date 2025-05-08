/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:36:18 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:36:20 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_images(t_data *data)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	data->objs->no = mlx_xpm_file_to_image(data->cub3d->mlx_init, data->no, &x,
			&y);
	data->objs->no_data = (int *)mlx_get_data_addr(data->objs->no,
			&data->objs->no_bpp, &data->objs->no_size_line,
			&data->objs->no_endian);
	data->objs->we = mlx_xpm_file_to_image(data->cub3d->mlx_init, data->we, &x,
			&y);
	data->objs->we_data = (int *)mlx_get_data_addr(data->objs->we,
			&data->objs->we_bpp, &data->objs->we_size_line,
			&data->objs->we_endian);
	data->objs->so = mlx_xpm_file_to_image(data->cub3d->mlx_init, data->so, &x,
			&y);
	data->objs->so_data = (int *)mlx_get_data_addr(data->objs->so,
			&data->objs->so_bpp, &data->objs->so_size_line,
			&data->objs->so_endian);
	data->objs->ea = mlx_xpm_file_to_image(data->cub3d->mlx_init, data->ea, &x,
			&y);
	data->objs->ea_data = (int *)mlx_get_data_addr(data->objs->ea,
			&data->objs->ea_bpp, &data->objs->ea_size_line,
			&data->objs->ea_endian);
}

void	set_player_information(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (player(data->map[x][y]))
			{
				data->raycast->posx = x + 0.5;
				data->raycast->posy = y + 0.5;
				data->user_type = data->map[x][y];
				return ;
			}
			y++;
		}
		x++;
	}
}

void	cam_options2(t_data *data)
{
	if (data->map[(int)data->raycast->posx][(int)data->raycast->posy] == 'W')
	{
		data->raycast->dirx = 0;
		data->raycast->diry = -1;
		data->raycast->planex = -0.60;
		data->raycast->planey = 0;
	}
	if (data->map[(int)data->raycast->posx][(int)data->raycast->posy] == 'E')
	{
		data->raycast->dirx = 0;
		data->raycast->diry = 1;
		data->raycast->planex = 0.60;
		data->raycast->planey = 0;
	}
}

void	cam_options(t_data *data)
{
	if (data->map[(int)data->raycast->posx][(int)data->raycast->posy] == 'N')
	{
		data->raycast->dirx = -1;
		data->raycast->diry = 0;
		data->raycast->planex = 0;
		data->raycast->planey = -0.60;
	}
	if (data->map[(int)data->raycast->posx][(int)data->raycast->posy] == 'S')
	{
		data->raycast->dirx = 1;
		data->raycast->diry = 0;
		data->raycast->planex = 0;
		data->raycast->planey = 0.60;
	}
	cam_options2(data);
}

void	control(t_data *data)
{
	data->raycast->key_left = 0;
	data->raycast->key_s = 0;
	data->raycast->key_right = 0;
	data->raycast->key_w = 0;
}
