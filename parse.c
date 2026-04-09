/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee <solee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:10:21 by solee             #+#    #+#             */
/*   Updated: 2026/04/07 16:54:15 by solee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	image_set(t_var *var, t_img *img)
// {
// 	int	img_width;
// 	int	img_height;

// 	img->img_floor = mlx_xpm_file_to_image(var->mlx,
// 			"./textures/0.xpm", &img_width, &img_height);
// 	img->img_wall = mlx_xpm_file_to_image(var->mlx,
// 			"./textures/1.xpm", &img_width, &img_height);
// 	img->img_p = mlx_xpm_file_to_image(var->mlx,
// 			"./textures/p.xpm", &img_width, &img_height);
// 	img->img_p_exit = mlx_xpm_file_to_image(var->mlx,
// 			"./textures/pe.xpm", &img_width, &img_height);
// 	img->img_exit = mlx_xpm_file_to_image(var->mlx,
// 			"./textures/e.xpm", &img_width, &img_height);
// 	img->img_apple = mlx_xpm_file_to_image(var->mlx,
// 			"./textures/c.xpm", &img_width, &img_height);
// }

// int	check_line(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == '\n')
// 		{
// 			line[i] = '\0';
// 			return (1);
// 		}
// 		else if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C'
// 			&& line[i] != '1' && line[i] != '0')
// 			return (-1);
// 		i++;
// 	}
// 	return (1);
// }

int	get_window_size(t_arg *arg, t_map *map, int fd)
{
	char	*line;
	int		i;
	int		j;

	(void)arg;
	i = 0;
	map->width = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		j = 0;
		while (line[j] && line[j] != '\n')
			j++;
		if (j > map->width)
			map->width = j;
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	map->height = i;
	return (0);
}

int	all_check(t_map *map)
{	
	if (map->no_path && map->so_path && map->we_path
			&& map->ea_path && map->floor_color && map->ceil_color)
		return(0);
	return(-1);
}

void	color_check(t_arg *arg, t_map *map, char *line)
{
	char	**tmp;
	
	tmp = ft_split(line, ' ');
	if (!tmp)
		exit_msg(arg, 3);
	if ((ft_strncmp(line, "F", 2) == 0))
	{
		map->floor_color = ft_atoi(tmp[1]);
	}
	if ((ft_strncmp(line, "C", 2) == 0))
	{
		map->ceil_color = ft_atoi(tmp[1]);
	}
	free_str(tmp);
}

void	texture_check(t_arg *arg, t_map *map, char *line)
{
	char	**tmp;
	
	tmp = ft_split(line, ' ');
	if (!tmp)
		exit_msg(arg, 3);
	if ((ft_strncmp(line, "NO", 3) == 0))
	{
		map->no_path = tmp[1];
	}
	if ((ft_strncmp(line, "SO", 3) == 0))
	{
		map->so_path = tmp[1];
	}
	if ((ft_strncmp(line, "WE", 3) == 0))
	{
		map->we_path = tmp[1];
	}
	if ((ft_strncmp(line, "EA", 3) == 0))
	{
		map->ea_path = tmp[1];
	}
	free_str(tmp);
}

int	img_parse(t_arg *arg, t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		texture_check(arg, map, line);
		color_check(arg, map, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (all_check(map) < 0)
		return(0);
	return (1);
}

// int	map_parse(t_arg *arg, t_map *map, int fd)
// {
// 	char	**map;
// 	char	*line;
// 	int		i;
// 	int		ret;

// 	i = 0;
// 	ret = 0;
// 	map = malloc(sizeof(char *) * (map->height + 1));
// 	if (!(map))
// 		return (-1);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		if (check_line(line) < 0)
// 			ret = 1;
// 		map[i] = ft_strdup(line);
// 		free(line);
// 		i++;
// 		line = get_next_line(fd);
// 	}
// 	map[game->window_y] = NULL;
// 	game->map = map;
// 	if (ret == 1)
// 		return (-1);
// 	return (1);
// }