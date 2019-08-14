/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 22:30:24 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:17:43 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	main(int argc, char **argv)
{
	t_image img;

	if (argc != 2)
		usage();
	else
	{
		parsing(argv[1], &img);
		init(&img);
		loop_fractals(&img);
		mlx_hook(img.mlx_window, 6, 0, mouse_move, &img);
		mlx_hook(img.mlx_window, 2, 0, key_press, &img);
		mlx_hook(img.mlx_window, 4, 0, mouse_press, &img);
		mlx_hook(img.mlx_window, 17, 0, ft_close, &img);
		mlx_loop(img.mlx_ptr);
	}
	return (0);
}
