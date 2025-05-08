/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:34:44 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:34:46 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	press(int k, void *dataa)
{
	t_data	*data;

	data = (t_data *)dataa;
	if (k == 13)
		data->raycast->key_w = 1;
	if (k == 1)
		data->raycast->key_s = 1;
	if (k == 123)
		data->raycast->key_left = 1;
	if (k == 124)
		data->raycast->key_right = 1;
	if (k == 2)
		data->raycast->key_a = 1;
	if (k == 0)
		data->raycast->key_d = 1;
	else if (k == 53)
	{
		exit(0);
	}
	return (0);
}

int	rele(int k, t_data *data)
{
	if (k == 13)
		data->raycast->key_w = 0;
	if (k == 1)
		data->raycast->key_s = 0;
	if (k == 123)
		data->raycast->key_left = 0;
	if (k == 124)
		data->raycast->key_right = 0;
	if (k == 2)
		data->raycast->key_a = 0;
	if (k == 0)
		data->raycast->key_d = 0;
	return (0);
}

void	right_wall_other_case(t_data *data, int i)
{
	data->c_flag = 1;
	while (i > 0)
	{
		check_all_map(data, i - 1);
		i--;
	}
}

int	control_for_map(t_data *data, int **i)
{
	if (data->file[*(*(i))] == '1' || data->file[*(*(i))] == '0')
		return (1);
	else if (data->file[*(*(i))] == 'N' || data->file[*(*(i))] == 'E')
		return (1);
	else if (data->file[*(*(i))] == 'W' || data->file[*(*(i))] == 'S')
		return (1);
	else
		return (0);
}

int	name_control(char *av)
{
	int	tmp;

	tmp = ft_strlen1(&av[1]);
	if ((av[tmp - 1] != 'b' && av[tmp - 2] != 'u' && av[tmp - 3] != 'c'
			&& av[tmp - 4] != '.') && tmp <= 9)
		return (0);
	else
		return (1);
}
