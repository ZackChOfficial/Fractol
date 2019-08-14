/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multijulia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 21:50:03 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:21:35 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	multijulia_calcul(struct s_image *img)
{
	double	u;
	double	p;

	calcul(img);
	while (img->number.x + img->number.y <= 4 && img->i < img->maxi)
	{
		u = img->n * atan2(img->clx_nb.y, img->clx_nb.x);
		p = pow(img->number.x + img->number.y, img->n >> 1);
		img->temp.x = p * cos(u) + img->mouse.x;
		img->clx_nb.y = p * sin(u) + img->mouse.y;
		img->clx_nb.x = img->temp.x;
		if (fabsl(img->temp.x - img->temp.y) < 0.000000001)
		{
			img->i = img->maxi;
			break ;
		}
		img->temp.y = img->temp.x;
		calcul(img);
		img->i++;
	}
	put_pixel(img, img->j, img->k);
}

void	multijulia(t_image *img)
{
	img->function = multijulia_calcul;
	create_threads(img);
	mlx_put_image_to_window(img->mlx_image,
			img->mlx_window, img->mlx_img_ptr, 0, 0);
}
