/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:34:54 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:34:56 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_direction(t_data *data, char **av)
{
	int	i;

	i = 0;
	while (data->file[i] != '\0')
	{
		get_direction_other_case(data, &i);
		if (no_case(data, &i) == 1)
			get_no_textures(data, &i);
		else if (so_case(data, &i))
			get_so_textures(data, &i);
		else if (we_case(data, &i))
			get_we_textures(data, &i);
		else if (ea_case(data, &i))
			get_ea_textures(data, &i);
		else if (floor_case(data, &i))
			get_floor(data, &i);
		else if (ceil_case(data, &i))
			get_ceil(data, &i);
		else if (is_true_value(data) == 1)
			break ;
		i++;
	}
	get_direction_other_case2(data, av, i);
}

void	get_file(char **av, t_data *data)
{
	int		fd;
	char	*gnlstr;

	fd = open(av[1], O_RDWR);
	if (fd == -1)
		ft_error(data, "file is not exist");
	gnlstr = get_next_line(fd);
	if (!gnlstr)
		ft_error(data, "empty file");
	data->file = ft_strdup1(gnlstr);
	free(gnlstr);
	gnlstr = get_next_line(fd);
	while (gnlstr != NULL)
	{
		data->file = ft_strjoin1(data->file, gnlstr);
		gnlstr = get_next_line(fd);
	}
	close(fd);
}

void	map_counter(t_data *data, int *i)
{
	int	j;

	j = *(i);
	data->map_len = 0;
	while (data->file[j] != '\0')
	{
		while (data->file[j] == ' ' || data->file[j] == '\n')
			j++;
		if (data->file[j] != '\0' && data->file[j] != '\n')
		{
			data->map_len++;
			if (data->file[j] >= 9 && data->file[j] <= 13)
				ft_error(data, "error");
			if (data->map_len == 1)
				data->start_location = j;
			while (data->file[j] != '\0' && data->file[j] != '\n')
				j++;
		}
	}
}

int	map_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	else if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W') && (line[i + 1] == '0' || line[i + 1] == '1'))
		return (1);
	return (0);
}

void	get_map(t_data *data, char **av)
{
	int		k;
	char	*str;
	int		fd;

	fd = open(av[1], O_RDONLY);
	k = 0;
	if (data->map_flag == 0)
		data->map = ft_calloc(data->map_len + 1, sizeof(char *));
	if (!data->map)
		return ;
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (map_start(str) == 1)
		{
			data->map[k] = ft_strdup1(str);
			k++;
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	data->map_flag = 1;
}
