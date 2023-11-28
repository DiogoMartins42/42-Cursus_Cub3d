/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:52:08 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/24 19:53:58 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*free_rgb(char *str, char **s, int *rgb)
{
	int	i;

	free(str);
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	if (rgb)
		free(rgb);
	return (NULL);
}

bool	is_rgb_valid(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\n')
		return (NULL);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

int	*save_rgb(char *str)
{
	int		*rgb;
	char	**s;
	int		i;

	rgb = malloc(3 * sizeof(int));
	s = ft_split(str, ',');
	i = 0;
	while (i < 3)
	{
		if (!is_rgb_valid(s[i]))
			return (free_rgb(str, s, rgb));
		rgb[i] = ft_atoi(s[i]);
		if (rgb[i] > 255)
			return (free_rgb(str, s, rgb));
		i++;
	}
	if (s[3])
		return (free_rgb(str, s, rgb));
	free_rgb(str, s, NULL);
	return (rgb);
}
