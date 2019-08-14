/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 20:56:29 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:17:40 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int		color1(t_image *img)
{
	unsigned char	r;

	r = (cos(img->i * 0.1 + 2) * 128 + 127 + img->color) * 1.2;
	return (r << 16 | r);
}

int		color2(t_image *img)
{
	unsigned char	b;

	b = (cos(img->i * 0.1 + 8) * 128 + 127 + img->color) * 1.2;
	return (b << 16 | b << 8 | b);
}

int		color3(t_image *img)
{
	unsigned char	g;

	g = (cos(img->i * 0.09 + 4) * 128 + 127 + img->color) * 1.2;
	return (g << 8 | g);
}

int		color4(t_image *img)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (cos(img->i * 0.09 + 2) * 128 + 127 + img->color) * 1.2;
	g = (cos(img->i * 0.09 + 4) * 128 + 127 + img->color) * 1.2;
	b = (cos(img->i * 0.09 + 8) * 128 + 127 + img->color) * 1.2;
	return (r << 8 | g << 16 | b);
}

int		color5(t_image *img)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (cos(img->i * 0.09 + 2) * 128 + 127 + img->color) * 1.2;
	g = (cos(img->i * 0.09 + 4) * 128 + 127 + img->color) * 1.2;
	b = (cos(img->i * 0.09 + 8) * 128 + 127 + img->color) * 1.2;
	return (g << 8 | b);
}
