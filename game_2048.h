#ifndef GAME_2048_H
# define GAME_2048_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# include <mlx.h>

# define WHITE	0x00FFFFFF
# define BLACK	0x00000000
# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF

# define LEFT_ARROW		65361
# define UP_ARROW		65362
# define RIGHT_ARROW	65363
# define DOWN_ARROW		65364

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_data;

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	int		board[16];
}	t_vars;

int		create_trgb(int t, int r, int g, int b);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	draw_line(t_data *data, t_point start_point, t_point end_point, int color);
void	draw_square(t_data *data, t_point point1, t_point point2, int color);
void	draw_circle(t_data *data, t_point center, int radius, int color);
void	draw_triangle(t_data *data, t_point point1, t_point point2, t_point point3, int color);

int		key_press(int keycode, t_vars *vars);


void    draw_tile(t_vars *vars, int tile, int value);
void	spawn_tile(t_vars *vars, int tile);
void	start_game(t_vars *vars);
void	move_tiles(t_vars *vars, int dir);

void    refresh_screen(t_vars *vars);
int		random_tile(int *board);


#endif