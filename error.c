/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:57 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:59 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(t_data *data, char *message)
{
	if (data->cub3d)
		free(data->cub3d);
	if (data->objs)
		free(data->objs);
	if (data->raycast)
		free(data->raycast);
	if (data)
		free(data);
	(void)data;
	write(1, message, ft_strlen1(message));
	exit(1);
}

void	error_case(char *message)
{
	write(1, message, ft_strlen1(message));
	exit(1);
}
