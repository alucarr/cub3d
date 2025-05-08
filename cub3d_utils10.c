/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:35 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:36 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_direction_other_case(t_data *data, int *i)
{
	while (data->file[*(i)] == ' ' || (data->file[*(i)] <= 13
			&& data->file[*(i)] >= 9))
		(*i)++;
}

void	get_direction_other_case2(t_data *data, char **av, int i)
{
	if (is_true_value(data) == 1)
	{
		map_counter(data, &i);
		get_map(data, av);
		i = data->start_location;
		check_space(data);
		up_wall_control(data);
		down_wall_control(data);
		left_wall_control(data);
		right_wall_control(data);
		check_spaces(data);
		flood_fill(data);
		ft_free(data);
		get_map(data, av);
		if (data->player != 1)
			ft_error(data, "player error");
	}
	else
		ft_error(data, "error!");
}

int	no_case(t_data *data, int *i)
{
	if (data->file[*(i)] == 'N' && data->file[*(i) + 1] == 'O'
		&& (data->file[*(i) + 2] == ' ' || (data->file[*(i) + 2] >= 9
				&& data->file[*(i) + 2] <= 13)))
		return (1);
	return (0);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_len)
	{
		free(data->map[i]);
		i++;
	}
}

void	check_space(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_len)
	{
		if (data->map[i][0] != ' ')
			break ;
		i++;
	}
	if (i == data->map_len)
	{
		ft_error(data, "wrong value");
	}
}
