/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:46:18 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:17:42 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	julia_calcul(struct s_image *img)
{
	calcul(img);
	while (img->number.x + img->number.y <= 4 && img->i < img->maxi)
	{
		img->temp.x = img->number.x - img->number.y + img->mouse.x;
		img->clx_nb.y = 2 * img->clx_nb.x * img->clx_nb.y + img->mouse.y;
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

void	julia(t_image *img)
{
	img->function = julia_calcul;
	create_threads(img);
	mlx_put_image_to_window(img->mlx_image,
			img->mlx_window, img->mlx_img_ptr, 0, 0);
}
