/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:34:17 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:25:12 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	usage(void)
{
	ft_putstr("Usage: ./fractal  [option]\n");
	ft_putstr("Options:\n");
	ft_putstr("	Julia\n");
	ft_putstr("	Mandelbrot\n");
	ft_putstr("	Multibrot\n");
	ft_putstr("	Multijulia\n");
	ft_putstr("	Burningship\n");
	ft_putstr("	Movingship\n");
	ft_putstr("--------------------------\n");
	ft_putstr("Menu:\n");
	ft_putstr("  Top, Down, Right, Left : Move fractal\n");
	ft_putstr("  page up, page down: increase/decrease  Multibrot\n");
	ft_putstr("  n: next fractal\n");
	ft_putstr("  f: play with julia/multijulia\n");
	ft_putstr("  z: zoom-in fixed point\n");
	ft_putstr("  d: zoom-out fixed point\n");
	ft_putstr("  < >: play with color\n");
	ft_putstr("  c: change color\n");
	ft_putstr("  +/-: increase/decrease iteration\n");
	ft_putstr("  esc: exit\n");
	exit(1);
}
