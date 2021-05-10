/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuliao- <martinez@brhaka.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:41:02 by ejuliao-          #+#    #+#             */
/*   Updated: 2021/05/10 10:33:41 by ejuliao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_error(t_scene *scene, char *message)
{
	printf(COLOR_RED "Error\n" COLOR_NC);
	printf(COLOR_LIGHT_RED "%s\n" COLOR_NC, message);
	clean_exit(scene, 1);
	return (1);
}

int	clean_exit(t_scene *scene, int code)
{
	printf(COLOR_CYAN "\nExiting..." COLOR_NC "\n");
	if (scene->objects != NULL)
	{
		while (scene->objects->next != NULL)
		{
			if (scene->objects->object != NULL)
				free(scene->objects->object);
			if (scene->objects->prev != NULL)
				free(scene->objects->prev);
			scene->objects = scene->objects->next;
		}
		if (scene->objects->prev != NULL)
			free(scene->objects->prev);
	}
	exit(code);
}
