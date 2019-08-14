/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 20:55:37 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:21:14 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	ft_map(t_image *img, int i, int j)
{
	img->clx_nb.x = ((img->max.x - img->min.x)
				/ (long double)WIDTH) * j + img->min.x;
	img->clx_nb.y = ((img->max.y - img->min.y)
				/ (long double)HEIGHT) * i + img->min.y;
}

void	parsing(char *str, t_image *img)
{
	if (!strcmp(str, "Julia"))
		img->func = 0;
	else if (!strcmp(str, "Mandelbrot"))
		img->func = 1;
	else if (!strcmp(str, "Multibrot"))
		img->func = 2;
	else if (!strcmp(str, "Multijulia"))
		img->func = 3;
	else if (!strcmp(str, "Burningship"))
		img->func = 4;
	else if (!strcmp(str, "Movingship"))
		img->func = 5;
	else
		usage();
}

void	calcul(t_image *img)
{
	img->number.x = img->clx_nb.x * img->clx_nb.x;
	img->number.y = img->clx_nb.y * img->clx_nb.y;
}

int		ft_close(void *param)
{
	t_image *img;

	img = (t_image *)param;
	exit(-1);
	return (1);
}
