/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipualtion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:50:55 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:17:44 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

long double	interpolate(long double start, long double end, long double fact)
{
	return (start + (end - start) * fact);
}

void		zoom(t_image *img, long double mousex,
		long double mousey, long double fact)
{
	long double	inter;

	inter = (1.0 / fact);
	mousex = ((img->max.x - img->min.x) /
			(long double)WIDTH) * mousex + img->min.x;
	mousey = ((img->max.y - img->min.y) /
			(long double)HEIGHT) * mousey + img->min.y;
	img->min.x = interpolate(mousex, img->min.x, inter);
	img->min.y = interpolate(mousey, img->min.y, inter);
	img->max.x = interpolate(mousex, img->max.x, inter);
	img->max.y = interpolate(mousey, img->max.y, inter);
}

void		loop_fractals2(t_image *img)
{
	if (img->func == 3)
	{
		multijulia(img);
		mlx_string_put(img->mlx_ptr, img->mlx_window, WIDTH / 2 - 100, 20,
				0xffffff, "Multijulia  n: ");
		mlx_string_put(img->mlx_ptr, img->mlx_window, WIDTH / 2 + 40, 20,
				0xffffff, ft_itoa(img->n));
	}
	else if (img->func == 4)
	{
		burningship(img);
		mlx_string_put(img->mlx_ptr, img->mlx_window, WIDTH / 2 - 60, 20,
				0xffffff, "Burningship");
	}
	else if (img->func == 5)
	{
		movingship(img);
		mlx_string_put(img->mlx_ptr, img->mlx_window, WIDTH / 2 - 60, 20,
				0xffffff, "Movingship");
	}
	mlx_string_put(img->mlx_ptr, img->mlx_window, 30, HEIGHT - 40,
			0xffffff, "iteration: ");
	mlx_string_put(img->mlx_ptr, img->mlx_window, 140, HEIGHT - 40,
			0xffffff, ft_itoa(img->maxi));
}

void		loop_fractals(t_image *img)
{
	clear(img);
	if (img->func == 0)
	{
		julia(img);
		mlx_string_put(img->mlx_ptr, img->mlx_window, WIDTH / 2 - 30, 20,
				0xffffff, "Julia");
	}
	else if (img->func == 1)
	{
		mandelbrot(img);
		mlx_string_put(img->mlx_ptr, img->mlx_window, WIDTH / 2 - 60, 20,
				0xffffff, "Mandelbrot");
	}
	else if (img->func == 2)
	{
		multilbrot(img);
		mlx_string_put(img->mlx_ptr, img->mlx_window, WIDTH / 2 - 100, 20,
				0xffffff, "Multibrot  n: ");
		mlx_string_put(img->mlx_ptr, img->mlx_window, WIDTH / 2 + 40, 20,
				0xffffff, ft_itoa(img->n));
	}
	loop_fractals2(img);
}

void		loop_coloring(t_image *img)
{
	if (img->coloring == color1)
		img->coloring = color2;
	else if (img->coloring == color2)
		img->coloring = color3;
	else if (img->coloring == color3)
		img->coloring = color4;
	else if (img->coloring == color4)
		img->coloring = color5;
	else
		img->coloring = color1;
}
