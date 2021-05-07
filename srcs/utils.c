/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuliao- <martinez@brhaka.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:51:57 by ejuliao-          #+#    #+#             */
/*   Updated: 2021/05/07 11:32:59 by ejuliao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

char	*get_file_no_ext(const char *path)
{
	char	*name;
	char	*name_no_path;
	int		i;

	name = ft_strtrim(path, ".rt");
	i = ft_last_index_of(name, '/');
	if (i == -1)
	{
		i = ft_last_index_of(name, '\\');
		if (i == -1)
			return (name);
	}
	name_no_path = ft_substr(name, i + 1, ft_strlen(name));
	free(name);
	return (name_no_path);
}

float	length_sqrt(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float	length(t_vec3 v)
{
	return (sqrt(length_sqrt(v)));
}

t_vec3	random_in_unit(void)
{
	t_vec3	rndm;

	while (true)
	{
		rndm = set(drand48(), drand48(), drand48());
		rndm = mul(rndm, 2.0f);
		rndm = sub(rndm, set(1.0f, 1.0f, 1.0f));
		if (length_sqrt(rndm) < 1.0f)
			break ;
	}
	return (rndm);
}
