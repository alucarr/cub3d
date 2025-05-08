/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:34:59 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:01 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_no_textures(t_data *data, int *i)
{
	int	j;
	int	tmp;
	int	tmp2;

	tmp = 0;
	tmp2 = *(i) + 2;
	other_case_for_direction(data, &i, &tmp, data->no_flag);
	data->no = ft_calloc((tmp - 1), sizeof(char));
	if (!data->no)
		return ;
	*(i) = tmp2;
	j = 0;
	while (data->file[*(i)] != '\0' && data->file[*(i)] != '\n')
	{
		if (data->file[*(i)] != ' ' && !(data->file[*(i)] <= 13
				&& data->file[*(i)] >= 9))
		{
			data->no[j] = data->file[*(i)];
			j++;
		}
		(*i)++;
	}
	data->no_flag = 1;
	texture_control(data, data->no);
}

void	get_so_textures(t_data *data, int *i)
{
	int	j;
	int	tmp;
	int	tmp2;

	tmp = 0;
	tmp2 = *(i) + 2;
	other_case_for_direction(data, &i, &tmp, data->so_flag);
	data->so = ft_calloc((tmp - 1), sizeof(char));
	if (!data->so)
		return ;
	*(i) = tmp2;
	j = 0;
	while (data->file[*(i)] != '\0' && data->file[*(i)] != '\n')
	{
		if (data->file[*(i)] != ' ' && !(data->file[*(i)] <= 13
				&& data->file[*(i)] >= 9))
		{
			data->so[j] = data->file[*(i)];
			j++;
		}
		(*i)++;
	}
	data->so_flag = 1;
	texture_control(data, data->so);
}

void	get_ea_textures(t_data *data, int *i)
{
	int	j;
	int	tmp;
	int	tmp2;

	tmp = 0;
	tmp2 = *(i) + 2;
	other_case_for_direction(data, &i, &tmp, data->ea_flag);
	data->ea = ft_calloc((tmp - 1), sizeof(char));
	if (!data->ea)
		return ;
	*(i) = tmp2;
	j = 0;
	while (data->file[*(i)] != '\0' && data->file[*(i)] != '\n')
	{
		if (data->file[*(i)] != ' ' && !(data->file[*(i)] <= 13
				&& data->file[*(i)] >= 9))
		{
			data->ea[j] = data->file[*(i)];
			j++;
		}
		(*i)++;
	}
	data->ea_flag = 1;
	texture_control(data, data->ea);
}

void	get_we_textures(t_data *data, int *i)
{
	int	j;
	int	tmp;
	int	tmp2;

	tmp = 0;
	tmp2 = *(i) + 2;
	other_case_for_direction(data, &i, &tmp, data->we_flag);
	data->we = ft_calloc((tmp - 1), sizeof(char));
	if (!data->we)
		return ;
	*(i) = tmp2;
	j = 0;
	while (data->file[*(i)] != '\0' && data->file[*(i)] != '\n')
	{
		if (data->file[*(i)] != ' ' && !(data->file[*(i)] <= 13
				&& data->file[*(i)] >= 9))
		{
			data->we[j] = data->file[*(i)];
			j++;
		}
		(*i)++;
	}
	data->we[j] = 0;
	data->we_flag = 1;
	texture_control(data, data->we);
}

void	other_case_for_direction(t_data *data, int **i, int *tmp, int value)
{
	if (value == 1)
		ft_error(data, "duplicate direction path");
	while (data->file[*(*(i))] != '\0' && data->file[*(*(i))] != '\n')
	{
		if (data->file[*(*(i))] != ' ' && !(data->file[*(*(i))] <= 13
				&& data->file[*(*(i))] >= 9))
			(*tmp)++;
		(**i)++;
	}
}
