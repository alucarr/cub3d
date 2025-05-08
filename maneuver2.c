/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maneuver2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:36:14 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:36:16 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_right(t_data *data)
{
	double	value;
	double	old_dirx;
	double	old_planex;

	value = 0.05;
	if (data->user_type == 'E' || data->user_type == 'W')
		value = -0.05;
	old_dirx = data->raycast->dirx;
	data->raycast->dirx = data->raycast->dirx * cos(value) - data->raycast->diry
		* sin(value);
	data->raycast->diry = old_dirx * sin(value) + data->raycast->diry
		* cos(value);
	old_planex = data->raycast->planex;
	data->raycast->planex = data->raycast->planex * cos(value)
		- data->raycast->planey * sin(value);
	data->raycast->planey = old_planex * sin(value) + data->raycast->planey
		* cos(value);
}

void	key_left(t_data *data)
{
	double	value;
	double	old_dirx;
	double	old_planex;

	value = -0.05;
	if (data->user_type == 'E' || data->user_type == 'W')
		value = 0.05;
	old_dirx = data->raycast->dirx;
	data->raycast->dirx = data->raycast->dirx * cos(value) - data->raycast->diry
		* sin(value);
	data->raycast->diry = old_dirx * sin(value) + data->raycast->diry
		* cos(value);
	old_planex = data->raycast->planex;
	data->raycast->planex = data->raycast->planex * cos(value)
		- data->raycast->planey * sin(value);
	data->raycast->planey = old_planex * sin(value) + data->raycast->planey
		* cos(value);
}

void	key_d1(t_data *data)
{
	if (data->map[(int)(data->raycast->posx + data->raycast->diry
			* 0.08)][(int)(data->raycast->posy)] == '0'
		|| player(data->map[(int)(data->raycast->posx + data->raycast->diry
				* 0.08)][(int)(data->raycast->posy)]))
		data->raycast->posx += data->raycast->diry * 0.08;
	if (data->map[(int)(data->raycast->posx)][(int)(data->raycast->posy
			- data->raycast->dirx * 0.08)] == '0'
		|| player(data->map[(int)(data->raycast->posx)]
			[(int)(data->raycast->posy
				- data->raycast->dirx * 0.08)]))
		data->raycast->posy -= data->raycast->dirx * 0.08;
}

void	key_a1(t_data *data)
{
	if (data->map[(int)(data->raycast->posx - data->raycast->diry
			* 0.08)][(int)(data->raycast->posy)] == '0'
		|| player(data->map[(int)(data->raycast->posx - data->raycast->diry
				* 0.08)][(int)(data->raycast->posy)]))
		data->raycast->posx -= data->raycast->diry * 0.08;
	if (data->map[(int)(data->raycast->posx)][(int)(data->raycast->posy
			+ data->raycast->dirx * 0.07)] == '0'
		|| player(data->map[(int)(data->raycast->posx)]
			[(int)(data->raycast->posy
				+ data->raycast->dirx * 0.07)]))
		data->raycast->posy += data->raycast->dirx * 0.07;
}
