/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:17:02 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:19:42 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	*thread(void *arg)
{
	t_image	*img;

	img = (t_image *)arg;
	while (++img->j < img->height_end)
	{
		img->k = img->width_start - 1;
		while (++img->k < img->width_end)
		{
			reset(img, img->k, img->j);
			img->function(img);
		}
	}
	pthread_exit(NULL);
}

void	create_threads(t_image *img)
{
	THREAD	tids[MAXTHREADS];
	t_image	images[MAXTHREADS];
	int		i;
	int		j;

	i = -1;
	while (++i < SQRT)
	{
		j = -1;
		while (++j < SQRT)
		{
			images[(i * SQRT) + j] = *img;
			images[(i * SQRT) + j].j = (HEIGHT / SQRT) * i - 1;
			images[(i * SQRT) + j].width_start = (WIDTH / SQRT) * j;
			images[(i * SQRT) + j].height_end = (HEIGHT / SQRT) * (i + 1);
			images[(i * SQRT) + j].width_end = (WIDTH / SQRT) * (j + 1);
			pthread_create(&tids[(i * SQRT) + j], NULL,
					thread, &images[(i * SQRT) + j]);
		}
	}
	i = -1;
	while (++i < MAXTHREADS)
		pthread_join(tids[i], NULL);
}
