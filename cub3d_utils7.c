/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:20 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:21 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tex(t_data *data)
{
	data->ceil_color = -1;
	data->floor_color = -1;
	data->cub3d->width = 1920;
	data->cub3d->height = 1080;
	data->player = 0;
	data->ea = NULL;
	data->no = NULL;
	data->we = NULL;
	data->so = NULL;
	data->map_flag = 0;
}

int	player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	flood_fill(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < data->map_len && data->map[i])
	{
		j = 0;
		len = ft_strlen1(data->map[i]);
		while (j < len && data->map[i][j] == ' ')
			j++;
		if (data->map[i][j] == '1' || data->map[i][j] == '0'
			|| player(data->map[i][j]))
		{
			loop(data, i, j);
			break ;
		}
		else if (data->map[i][j] != '\n' && data->map[i][j] != '\0')
			ft_error(data, "Some undefined characters\n");
	}
	flood_fill2(data);
}

void	loop(t_data *data, int i, int j)
{
	if (player(data->map[i][j]))
		data->player++;
	data->map[i][j] = '.';
	if (i > 0 && (data->map[i - 1][j] == '0' || data->map[i - 1][j] == '1'
			|| player(data->map[i - 1][j])))
		loop(data, i - 1, j);
	if (i < data->map_len - 1 && (data->map[i + 1][j] == '0' || data->map[i
			+ 1][j] == '1' || player(data->map[i + 1][j])))
		loop(data, i + 1, j);
	if (j > 0 && (data->map[i][j - 1] == '0' || data->map[i][j - 1] == '1'
			|| player(data->map[i][j - 1]) || data->map[i][j - 1] == ' '))
		loop(data, i, j - 1);
	if (j < ft_strlen1(data->map[i]) - 1 && (data->map[i][j + 1] == '0'
		|| data->map[i][j + 1] == '1'
			|| player(data->map[i][j + 1] || data->map[i][j + 1] == ' ')))
		loop(data, i, j + 1);
}

void	flood_fill2(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < data->map_len && data->map[i])
	{
		j = 0;
		len = ft_strlen1(data->map[i]) - 2;
		while (j < len)
		{
			if (data->map[i][j] == '.' || data->map[i][j] == '\n'
				|| data->map[i][j] == ' ')
				j++;
			else if (data->map[i][j] == '1' || data->map[i][j] == '0'
				|| player(data->map[i][j]))
				ft_error(data, "Unconnected maps are not supported\n");
			else
				ft_error(data, "Some undefined character\n");
		}
	}
}
