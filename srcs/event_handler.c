/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:29:09 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:18:43 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	mouse_move(int x, int y, void *param)
{
	t_image *img;

	img = (t_image *)param;
	if ((img->func == 0 || img->func == 3 || img->func == 5) && !img->fixed)
	{
		clear(img);
		img->mouse.x = (1.0 * x) / 600;
		img->mouse.y = (1.0 * y) / 600;
		if (img->func == 0)
			julia(img);
		else if (img->func == 3)
			multijulia(img);
		else
			movingship(img);
	}
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_image *img;

	img = (t_image *)param;
	if (keycode == 45)
		next_fractal(img);
	else if (keycode == 3)
		img->fixed = !img->fixed;
	else if (keycode == 6 || keycode == 2)
		zoom(img, img->zoom.x, img->zoom.y, keycode == 6 ? 1.45 : 0.7);
	else if (keycode == 47 || keycode == 43)
		img->color = (img->color + (keycode == 47 ? 1 : -1)) % 255;
	else if (keycode == 8)
		loop_coloring(img);
	else if (keycode == 69 || keycode == 78)
		img->maxi += (keycode == 69) ? 1 : -1;
	else if (keycode == 126 || keycode == 125 ||
			keycode == 123 || keycode == 124)
		ft_move(img, keycode);
	else if ((keycode == 116 || keycode == 121)
			&& (img->func == 2 || img->func == 3))
		img->n += keycode == 116 ? 1 : -1;
	else if (keycode == 53)
		ft_close(param);
	loop_fractals(img);
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_image		*img;

	img = (t_image *)param;
	img->zoom.x = 1.0 * x;
	img->zoom.y = 1.0 * y;
	if (button == 5)
		zoom(img, img->zoom.x, img->zoom.y, 0.7);
	else if (button == 4)
		zoom(img, img->zoom.x, img->zoom.y, 1.25);
	loop_fractals(img);
	return (0);
}
