/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:16:01 by metyasar          #+#    #+#             */
/*   Updated: 2023/08/22 17:30:31 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buffer)
{
	size_t	c;
	size_t	i;
	char	*res;

	c = 0;
	i = 0;
	res = malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
	if (res == NULL)
		return (NULL);
	while (str[c])
	{
		res[c] = str[c];
		c++;
	}
	while (buffer[i])
		res[c++] = buffer[i++];
	res[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	free(str);
	return (res);
}

char	*find_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*new_str(char *str)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!res)
		return (NULL);
	i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
