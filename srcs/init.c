/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 20:52:21 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:17:42 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	init(t_image *img)
{
	if (!(img->mlx_ptr = mlx_init()))
		exit(-1);
	if (!(img->mlx_window = mlx_new_window(img->mlx_ptr,
					WIDTH, HEIGHT, "fractal")))
		exit(-1);
	if (!(img->mlx_img_ptr = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT)))
		exit(-1);
	if (!(img->mlx_image = (int *)mlx_get_data_addr(img->mlx_img_ptr,
					&img->bpp, &img->line_size, &img->endian)))
		exit(-1);
	img->min.x = (1 - WIDTH / 2.0) * 6.0 / WIDTH;
	img->min.y = (1 - HEIGHT / 2.0) * 6.0 / WIDTH;
	img->max.x = (WIDTH - WIDTH / 2.0) * 6.0 / WIDTH;
	img->max.y = (HEIGHT - HEIGHT / 2.0) * 6.0 / WIDTH;
	img->mouse.x = 0.279;
	img->mouse.y = 0.579;
	img->fixed = 1;
	img->maxi = 30;
	img->color = 1;
	img->color_p = 1;
	img->n = 2;
	img->coloring = color2;
	img->zoom.x = WIDTH / 2 * 1.0;
	img->zoom.y = HEIGHT / 2 * 1.0;
}

void	reset(t_image *img, int j, int i)
{
	img->constant.x = (j - WIDTH / 2.0) * (4.0 / WIDTH);
	img->constant.y = (i - HEIGHT / 2.0) * (4.0 / HEIGHT);
	img->i = 0;
	ft_map(img, i, j);
	img->constant = img->clx_nb;
}

void	put_pixel(t_image *img, int i, int j)
{
	if (img->i < img->maxi)
		img->mlx_image[j + i * WIDTH] = img->coloring(img);
	else
		img->mlx_image[j + i * WIDTH] = 0x000000;
}

void	clear(t_image *img)
{
	mlx_destroy_image(img->mlx_ptr, img->mlx_img_ptr);
	mlx_clear_window(img->mlx_ptr, img->mlx_window);
	if (!(img->mlx_img_ptr = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT)))
		exit(-1);
	if (!(img->mlx_image = (int *)mlx_get_data_addr(img->mlx_img_ptr,
					&img->bpp, &img->line_size, &img->endian)))
		exit(-1);
}
