/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee <solee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:09:59 by solee             #+#    #+#             */
/*   Updated: 2026/04/07 16:54:18 by solee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_extension(char *file)
{
	char	*tmp;

	tmp = file;
	while (*file)
	{
		file++;
		if (*file == '.')
		{
			tmp = file;
			if ((file + 1) != NULL)
				file++;
		}
	}
	return (tmp);
}

int	is_file_valid(char *file)
{
	char	**path;
	int	i;

	i = 0;
	path = ft_split(file, '/');
	if (!path)
		return (-1);
	while (path[i])
		i++;
	if ((ft_strlen(path[i - 1]) == 4) && (ft_strncmp(path[i - 1], ".cub", 4) == 0))
		return (free_str(path), -1);
	free_str(path);
	if ((ft_strncmp(get_extension(file), ".cub", 4) == 0))
		return (0);
	return (-1);
}

void	init_data(t_arg *arg, char *file)
{
	int	fd1;
	int	fd2;

	if (is_file_valid(file) < 0)
		exit_msg(arg, 1);
	fd1 = open(file, O_RDONLY);
	fd2 = open(file, O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		exit_msg(arg, 2);
	if (get_window_size(arg, &(arg->map), fd1) < 0 || img_parse(arg, &(arg->map), fd2) < 0)
		exit_msg(arg, 3);
	printf("x :%d y : %d\n", arg->map.width, arg->map.height);
	printf("%s, %s, %s, %s\n %d, %d\n", arg->map.no_path, arg->map.so_path, arg->map.we_path, arg->map.ea_path, arg->map.floor_color, arg->map.ceil_color);
}