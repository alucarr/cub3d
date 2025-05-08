/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils11.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:39 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:40 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	so_case(t_data *data, int *i)
{
	if (data->file[*(i)] == 'S' && data->file[*(i) + 1] == 'O'
		&& (data->file[*(i) + 2] == ' ' || (data->file[*(i) + 2] >= 9
				&& data->file[*(i) + 2] <= 13)))
		return (1);
	return (0);
}

int	ea_case(t_data *data, int *i)
{
	if (data->file[*(i)] == 'E' && data->file[*(i) + 1] == 'A'
		&& (data->file[*(i) + 2] == ' ' || (data->file[*(i) + 2] >= 9
				&& data->file[*(i) + 2] <= 13)))
		return (1);
	return (0);
}

int	we_case(t_data *data, int *i)
{
	if (data->file[*(i)] == 'W' && data->file[*(i) + 1] == 'E'
		&& (data->file[*(i) + 2] == ' ' || (data->file[*(i) + 2] >= 9
				&& data->file[*(i) + 2] <= 13)))
		return (1);
	return (0);
}

int	floor_case(t_data *data, int *i)
{
	if (data->file[*(i)] == 'F' && (data->file[*(i) + 1] == ' '
			|| (data->file[*(i) + 1] >= 9 && data->file[*(i) + 1] <= 13)))
		return (1);
	return (0);
}

int	ceil_case(t_data *data, int *i)
{
	if (data->file[*(i)] == 'C' && (data->file[*(i) + 1] == ' '
			|| (data->file[*(i) + 1] >= 9 && data->file[*(i) + 1] <= 13)))
		return (1);
	return (0);
}
