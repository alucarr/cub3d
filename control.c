/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:34:24 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:34:34 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_exist(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		return (1);
}

void	texture_control(t_data *data, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error (data, "file does not exist");
}

void	control_and_set(t_data *data, char *str, int j)
{
	int	i;
	int	flag;
	int	tmp;

	flag = 0;
	i = 0;
	tmp = 0;
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0') && str[i] != ',')
			ft_error(data, "is not digit");
		if (str[i] == ',')
			flag++;
		if (str[i] == ',' && flag == 2)
			tmp = i;
		i++;
	}
	if (!(str[tmp + 1] >= '0' && str[tmp + 1] <= '9') || flag != 2)
		ft_error(data, "wrong value");
	data->colors = ft_split(str, ',');
	if (j == 0)
		ceil_other_func(data);
	else if (j == 1)
		floor_other_func(data);
}

void	ceil_other_func(t_data *data)
{
	int	i;

	i = 0;
	while (data->colors[i] != NULL)
	{
		if (ft_strlen1(data->colors[i]) > 3)
			ft_error(data, "wrong number entered");
		data->c_color[i] = ft_atoi(data->colors[i], data);
		i++;
	}
	data->ceil_color = (data->c_color[0] << 16) + (data->c_color[1] << 8)
		+ data->c_color[2];
	free(data->colors[0]);
	free(data->colors[1]);
	free(data->colors[2]);
	free(data->colors);
}

void	floor_other_func(t_data *data)
{
	int	i;

	i = 0;
	while (data->colors[i] != NULL)
	{
		if (ft_strlen1(data->colors[i]) > 3)
			ft_error(data, "wrong number entered");
		data->f_color[i] = ft_atoi(data->colors[i], data);
		i++;
	}
	data->floor_color = (data->f_color[0] << 16) + (data->f_color[1] << 8)
		+ data->f_color[2];
	free(data->colors[0]);
	free(data->colors[1]);
	free(data->colors[2]);
	free(data->colors);
}
