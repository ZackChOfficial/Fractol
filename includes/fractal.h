/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 22:15:04 by zchatoua          #+#    #+#             */
/*   Updated: 2019/08/13 20:18:09 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <pthread.h>
# define WIDTH 900
# define HEIGHT 900
# define MAXTHREADS 4
# define SQRT 2
# define THREAD pthread_t

typedef struct			s_complex
{
	long double				x;
	long double				y;
}						t_complex;

typedef struct			s_image
{
	void				*mlx_ptr;
	void				*mlx_window;
	void				*mlx_img_ptr;
	int					*mlx_image;
	int					bpp;
	int					color;
	int					color_p;
	int					line_size;
	int					endian;
	int					func;
	int					fixed;
	t_complex			constant;
	t_complex			mouse;
	t_complex			clx_nb;
	t_complex			min;
	t_complex			max;
	t_complex			temp;
	t_complex			number;
	t_complex			zoom;
	int					(*coloring)(struct s_image *img);
	void				(*function)(struct s_image *img);
	int					maxi;
	int					i;
	int					j;
	int					k;
	int					n;
	int					height_start;
	int					width_start;
	int					height_end;
	int					width_end;
}						t_image;

/*
** Event Handler
*/

int						mouse_move(int x, int y, void *param);
int						mouse_press(int button, int x, int y, void *param);
int						key_press(int keycode, void *param);
int						ft_close(void *param);

/*
** Colors
*/

int						color1(t_image *img);
int						color2(t_image *img);
int						color3(t_image *img);
int						color4(t_image *img);
int						color5(t_image *img);
void					loop_coloring(t_image *img);

/*
** Fractals
*/

void					mandelbrot(t_image *img);
void					julia(t_image *img);
void					multilbrot(t_image *img);
void					multijulia(t_image *img);
void					burningship(t_image *img);
void					movingship(t_image *img);
void					calcul(t_image *img);

/*
** Manipulate Fractals
*/

void					loop_fractals(t_image *img);
void					ft_move(t_image *img, int key);
void					next_fractal(t_image *img);
void					loop_fractals(t_image *img);

/*
** Zoom and Parsing
*/

void					ft_map(t_image *img, int i, int j);
long double				interpolate(long double start,
							long double end, long double fact);
void					zoom(t_image *img, long double mousex,
							long double mousey, long double fact);

/*
** Init
*/

void					init(t_image *img);
void					reset(t_image *img, int j, int i);
void					clear(t_image *img);

/*
** Utils functions
*/

void					usage();
void					parsing(char *str, t_image *img);
void					put_pixel(t_image *img, int i, int j);

/*
** Threads
*/

void					create_threads(t_image *img);
void					*thread(void *arg);
#endif
