/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee <solee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:57:06 by solee             #+#    #+#             */
/*   Updated: 2026/04/07 15:57:43 by solee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_msg(t_arg *arg, int msg)
{
	(void)arg;
	if (msg == 0)
		printf("Need one map file\n");
	if (msg == 1)
		printf("Map is not a \".cub\" file\n");
	if (msg == 2)
		printf("Map unable to open\n");
	if (msg == 3)
		printf("Map unvaild\n");
	exit(1);
}