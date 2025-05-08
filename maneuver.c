/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maneuver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:36:10 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:36:11 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w(t_data *data)
{
	if (data->map[(int)(data->raycast->posx + data->raycast->dirx
			* 0.08)][(int)(data->raycast->posy)] == '0'
		|| player(data->map[(int)(data->raycast->posx + data->raycast->dirx
				* 0.08)][(int)(data->raycast->posy)]))
		data->raycast->posx += data->raycast->dirx * 0.08;
	if (data->map[(int)data->raycast->posx][(int)(data->raycast->posy
		+ data->raycast->diry * 0.08)] == '0'
		|| player(data->map[(int)data->raycast->posx][(int)(data->raycast->posy
				+ data->raycast->diry * 0.08)]))
		data->raycast->posy += data->raycast->diry * 0.08;
}

void	key_s(t_data *data)
{
	if (data->map[(int)(data->raycast->posx - data->raycast->dirx
			* 0.08)][(int)(data->raycast->posy)] == '0'
		|| player(data->map[(int)(data->raycast->posx - data->raycast->dirx
				* 0.08)][(int)(data->raycast->posy)]))
		data->raycast->posx -= data->raycast->dirx * 0.08;
	if (data->map[(int)(data->raycast->posx)][(int)(data->raycast->posy
		- data->raycast->diry * 0.08)] == '0'
			|| player(data->map[(int)(data->raycast->posx)]
				[(int)(data->raycast->posy
				- data->raycast->diry * 0.08)]))
		data->raycast->posy -= data->raycast->diry * 0.08;
}

void	key_a(t_data *data)
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

void	key_d(t_data *data)
{
	if (data->map[(int)(data->raycast->posx - data->raycast->diry
			* 0.08)][(int)(data->raycast->posy)] == '0'
		|| player(data->map[(int)(data->raycast->posx - data->raycast->diry
				* 0.08)][(int)(data->raycast->posy)]))
		data->raycast->posx -= data->raycast->diry * 0.08;
	if (data->map[(int)(data->raycast->posx)][(int)(data->raycast->posy
			+ data->raycast->dirx * 0.08)] == '0'
		|| player(data->map[(int)(data->raycast->posx)]
			[(int)(data->raycast->posy
				+ data->raycast->dirx * 0.08)]))
		data->raycast->posy += data->raycast->dirx * 0.08;
}

void	maneuver(t_data *data)
{
	if (data->raycast->key_w)
		key_w(data);
	if (data->raycast->key_s)
		key_s(data);
	if (data->raycast->key_left)
		key_left(data);
	if (data->raycast->key_right)
		key_right(data);
	if (data->raycast->key_a)
	{
		if (data->user_type == 'N' || data->user_type == 'S')
			key_a1(data);
		else
			key_a(data);
	}
	if (data->raycast->key_d)
	{
		if (data->user_type == 'N' || data->user_type == 'S')
			key_d1(data);
		else
			key_d(data);
	}
}
