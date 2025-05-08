/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:04 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:06 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_floor(t_data *data, int *i)
{
	int	j;
	int	tmp;
	int	tmp2;

	tmp = 0;
	tmp2 = *(i) + 2;
	other_case_floor_color(data, &i, &tmp, 1);
	data->f_for_tmp = ft_calloc(tmp, sizeof(char));
	if (!data->f_for_tmp)
		return ;
	j = 0;
	*(i) = tmp2;
	while (data->file[*(i)] != '\0' && data->file[*(i)] != '\n')
	{
		if (data->file[*(i)] != ' ' && !(data->file[*(i)] <= 13
				&& data->file[*(i)] >= 9))
		{
			data->f_for_tmp[j] = data->file[*(i)];
			j++;
		}
		(*i)++;
	}
	data->floor_flag = 1;
	control_and_set(data, data->f_for_tmp, 1);
}

void	get_ceil(t_data *data, int *i)
{
	int	j;
	int	tmp;
	int	tmp2;

	tmp = 0;
	tmp2 = *(i) + 2;
	other_case_floor_color1(data, &i, &tmp, 2);
	data->c_for_tmp = ft_calloc(tmp, sizeof(char));
	if (!data->c_for_tmp)
		return ;
	j = 0;
	*(i) = tmp2;
	while (data->file[*(i)] != '\0' && data->file[*(i)] != '\n')
	{
		if (data->file[*(i)] != ' ' && !(data->file[*(i)] <= 13
				&& data->file[*(i)] >= 9))
		{
			data->c_for_tmp[j] = data->file[*(i)];
			j++;
		}
		(*i)++;
	}
	data->ceil_flag = 1;
	control_and_set(data, data->c_for_tmp, 0);
}

void	other_case_floor_color(t_data *data, int **i, int *tmp, int flag)
{
	if (data->floor_flag == 1 && flag == 1)
		ft_error(data, "duplicate direction path");
	while (data->file[*(*(i))] != '\0' && data->file[*(*(i))] != '\n')
	{
		if (data->file[*(*(i))] != ' ' && !(data->file[*(*(i))] <= 13
				&& data->file[*(*(i))] >= 9))
			(*tmp)++;
		(**i)++;
	}
}

void	other_case_floor_color1(t_data *data, int **i, int *tmp, int flag)
{
	if (data->ceil_flag == 1 && flag == 2)
		ft_error(data, "duplicate direction path");
	while (data->file[*(*(i))] != '\0' && data->file[*(*(i))] != '\n')
	{
		if (data->file[*(*(i))] != ' ' && !(data->file[*(*(i))] <= 13
				&& data->file[*(*(i))] >= 9))
			(*tmp)++;
		(**i)++;
	}
}
