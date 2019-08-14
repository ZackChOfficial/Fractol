/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 21:15:46 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:17:45 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	next_fractal(t_image *img)
{
	img->func = (img->func + 1) % 6;
	img->min.x = (1 - WIDTH / 2.0) * 6.0 / WIDTH;
	img->min.y = (1 - HEIGHT / 2.0) * 6.0 / WIDTH;
	img->max.x = (WIDTH - WIDTH / 2.0) * 6.0 / WIDTH;
	img->max.y = (HEIGHT - HEIGHT / 2.0) * 6.0 / WIDTH;
	img->mouse.x = 0.279;
	img->mouse.y = 0.579;
	img->maxi = 30;
	img->n = 2;
	img->zoom.x = WIDTH / 2 * 1.0;
	img->zoom.y = HEIGHT / 2 * 1.0;
}

void	ft_move(t_image *img, int key)
{
	if (key == 126)
	{
		img->min.y += 0.08;
		img->max.y += 0.08;
	}
	else if (key == 125)
	{
		img->min.y -= 0.08;
		img->max.y -= 0.08;
	}
	else if (key == 123)
	{
		img->min.x += 0.08;
		img->max.x += 0.08;
	}
	else
	{
		img->min.x -= 0.08;
		img->max.x -= 0.08;
	}
}
