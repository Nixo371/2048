#include "game_2048.h"

int	create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	draw_line(t_data *data, t_point start_point, t_point end_point, int color)
{
	int		x;
	int		y;
	double	xdif;
	double	ydif;
	double	ratio;
	double	new_ratio;
	int		xinc;
	int		yinc;

	x = start_point.x;
	y = start_point.y;

	xdif = end_point.x - start_point.x;
	ydif = end_point.y - start_point.y;

	xinc = 0;
	yinc = 0;

	if (xdif > 0)
		xinc = 1;
	if (xdif < 0)
		xinc = -1;
	if (ydif > 0)
		yinc = 1;
	if (ydif < 0)
		yinc = -1;

	if (ydif == 0)
		ydif = 1;

	ratio = xdif / ydif;
	if (ratio < 0)
		ratio = -ratio;

	while(x != end_point.x || y != end_point.y)
	{
		my_mlx_pixel_put(data, x, y, color);

		xdif = x - end_point.x;
		ydif = y - end_point.y;
		new_ratio = xdif / ydif;
		if (new_ratio < 0)
			new_ratio = -new_ratio;

		if (ydif == 0)
			ydif = 1;

		if (new_ratio < ratio)
		{
			y += yinc;
		}
		else if (new_ratio > ratio)
		{
			x += xinc;
		}
		else
		{
			y += yinc;
			x += xinc;
		}
	}
}

void	draw_square(t_data *data, t_point point1, t_point point2, int color)
{
	int		dif;
	int		inc;
	t_point	p1;
	t_point p2;

	dif = point2.y - point1.y;
	if (dif == 0)
	{
		draw_line(data, point1, point2, color);
		return;
	}
	if (dif > 0)
		inc = 1;
	if (dif < 0)
		inc = -1;

	p1.x = point1.x;
	p1.y = point1.y;

	p2.x = point2.x;
	p2.y = point1.y;
	while(p1.y != point2.y)
	{
		draw_line(data, p1, p2, color);
		p1.y += inc;
		p2.y += inc;
	}

}

void	draw_circle(t_data *data, t_point center, int radius, int color)
{
	int	x;
	int	y;

	x = center.x - radius;
	y = center.y - radius;
	while(y < center.y + radius)
	{
		while(x < center.x + radius)
		{
			if ( (radius * radius) > ((x - center.x) * (x - center.x)) + ((y - center.y) * (y - center.y)) )
				my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
		x = radius - center.x;
	}
}

void	draw_triangle(t_data *data, t_point point1, t_point point2, t_point point3, int color)
{
	draw_line(data, point1, point2, color);
	draw_line(data, point2, point3, color);
	draw_line(data, point3, point1, color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}