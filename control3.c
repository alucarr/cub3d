/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:34:39 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:34:40 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_wall_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i][0] && i < data->map_len - 1)
	{
		if (data->map[i][0] == '1')
			i++;
		else if (data->map[i][0] == ' ')
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] == '1')
				{
					i++;
					break ;
				}
				else
					j += check_walls(data, data->map[i][j]);
			}
		}
		else
			ft_error(data, "\n");
	}
}

void	right_wall_control(t_data *data)
{
	int	i;
	int	j;
	int	y;

	i = -1;
	y = ft_strlen1(data->map[0]) - 2;
	data->c_flag = 0;
	while (++i < data->map_len && data->map[i])
	{
		check_all_map(data, i);
		j = ft_strlen1(data->map[i]);
		while (data->map[i][j] != '1' && data->map[i][j] != '0')
			j--;
		y = right_wall(data, i, y);
		while (y < j)
		{
			if (data->map[i][j] && data->map[i][j] != '1'
				&& data->map[i][j] != ' ')
				ft_error(data, "Map is not surrounded by walls3\n");
			y++;
		}
		if (data->map[i][j] && data->map[i][j] != '1')
			ft_error(data, "Map is not surrounded by walls4\n");
	}
	right_wall_other_case(data, i);
}

int	right_wall(t_data *data, int i, int y)
{
	if (i - 1 >= 0 && ft_strlen1(data->map[i]) > ft_strlen1(data->map[i - 1]))
		y = ft_strlen1(data->map[i - 1]) - 1;
	if (i + 1 < data->map_len - 1 && i - 1 >= 0
		&& ft_strlen1(data->map[i]) > ft_strlen1(data->map[i + 1])
		&& ft_strlen1(data->map[i + 1]) < ft_strlen1(data->map[i - 1]))
		y = ft_strlen1(data->map[i + 1]) - 1;
	if (i + 1 == data->map_len - 1
		&& ft_strlen1(data->map[i]) > ft_strlen1(data->map[i + 1])
		&& ft_strlen1(data->map[i + 1]) < ft_strlen1(data->map[i - 1]))
		y = ft_strlen1(data->map[i + 1]);
	return (y);
}

void	check_all_map(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->map[i][j + 1] != '\n' && data->map[i][j + 1])
		j++;
	if (data->c_flag == 0)
	{
		if (data->map[i + 1])
		{
			if ((ft_strlen1(data->map[i]) < ft_strlen1(data->map[i + 1])))
				i++;
		}
		else
			return ;
		while (data->map[i][j] != '\n')
		{
			if (data->map[i][j] == '0')
			{
				ft_error(data, "hata");
			}
			j++;
		}
	}
	other_case2(data, i, j);
}

void	other_case2(t_data *data, int i, int j)
{
	if (data->c_flag == 1)
	{
		if (i > 0)
		{
			if ((ft_strlen1(data->map[i]) < ft_strlen1(data->map[i - 1])))
				i--;
		}
		else
			return ;
		while (data->map[i][j] != '\n')
		{
			if (data->map[i][j] == '0')
			{
				ft_error(data, "hata");
			}
			j++;
		}
	}
}
