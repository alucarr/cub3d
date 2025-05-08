/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:34:27 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:34:30 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_wall_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[0][i] != '\0' && data->map[0][i + 1] != '\n')
	{
		if (data->map[0][i] == '1')
			i++;
		else if (data->map[0][i] == ' ')
		{
			j = 0;
			while (j < data->map_len)
			{
				if (data->map[j][i] == '1')
				{
					i++;
					break ;
				}
				else
					j += check_walls(data, data->map[j][i]);
			}
		}
		else
			ft_error(data, "Map is not surrounded by walls1\n");
	}
}

void	down_wall_control(t_data *data)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	if (data->map[data->map_len - 1])
	{
		o = ft_strlen1(data->map[data->map_len - 1]);
	}
	else
		ft_error(data, "error");
	while (data->map[data->map_len - 1][i] && data->map[data->map_len
		- 1][i] != '\n' && data->map[data->map_len - 1][i] != 0 && i < (o - 2))
	{
		if (data->map[data->map_len - 1][i] == '1')
			i++;
		else if (data->map[data->map_len - 1][i] == ' ')
			i = down_wall(data, i);
		else
			ft_error(data, "Map is not surrounded by walls5\n");
	}
}

int	down_wall(t_data *data, int i)
{
	int	j;

	j = data->map_len - 1;
	while (data->map[j][i])
	{
		if (data->map[j][i] == '1')
		{
			i++;
			break ;
		}
		else
			j -= check_walls(data, data->map[j][i]);
	}
	return (i);
}

int	check_walls(t_data *data, char c)
{
	if (c == ' ')
		return (1);
	else
		ft_error(data, "Map is not surrounded by walls2\n");
	return (0);
}
