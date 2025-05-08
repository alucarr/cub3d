/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:13 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:15 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	space_sur(t_data *data, int i, int j)
{
	if (j + 1 < ft_strlen1(data->map[i]) && (data->map[i][j + 1] == '0'
		|| player(data->map[i][j + 1])) && data->map[i][j + 1])
		ft_error(data, "space errora");
	else if (j > 0 && (data->map[i][j - 1] == '0' || player(data->map[i][j
			- 1])) && data->map[i][j - 1])
		ft_error(data, "space errorb");
	else if (i + 1 < data->map_len && (data->map[i + 1][j] == '0'
		|| player(data->map[i + 1][j])) && (data->map[i + 1][j]))
		ft_error(data, "space errorc");
	else if (i > 0 && (data->map[i - 1][j] == '0' || player(data->map[i
				- 1][j])) && data->map[i -1][j])
		ft_error(data, "space errord");
}

void	check_spaces(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_len && data->map[i])
	{
		j = 0;
		while (j < ft_strlen1(data->map[i]))
		{
			if (data->map[i][j] == ' ')
				space_sur(data, i, j);
			j++;
		}
	}
}

int	control_map(t_data *data, int **i)
{
	if (data->file[*(*(i))] == '1' || data->file[*(*(i))] == '0')
		return (0);
	else if (data->file[*(*(i))] == 'N' || data->file[*(*(i))] == 'E')
		return (0);
	else if (data->file[*(*(i))] == 'W' || data->file[*(*(i))] == 'S')
		return (0);
	else
		return (1);
}
