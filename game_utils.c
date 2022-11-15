#include "game_2048.h"

void    draw_tile(t_vars *vars, int tile, int value)
{
	void    *img;
	int     width;
	int     height;
	char    *img_file;

	img_file = malloc((24 * sizeof(char)) + 1);
	img_file = "./pieces/xpm195/0.xpm";
	if (value == 2)
		img_file = "./pieces/xpm195/2.xpm";
	else if (value == 4)
		img_file = "./pieces/xpm195/4.xpm";
	else if (value == 8)
		img_file = "./pieces/xpm195/8.xpm";
	else if (value == 16)
		img_file = "./pieces/xpm195/16.xpm";
	else if (value == 32)
		img_file = "./pieces/xpm195/32.xpm";
	else if (value == 64)
		img_file = "./pieces/xpm195/64.xpm";
	else if (value == 128)
		img_file = "./pieces/xpm195/128.xpm";
	else if (value == 256)
		img_file = "./pieces/xpm195/256.xpm";
	else if (value == 512)
		img_file = "./pieces/xpm195/512.xpm";
	else if (value == 1024)
		img_file = "./pieces/xpm195/1024.xpm";
	else if (value == 2048)
		img_file = "./pieces/xpm195/2048.xpm";
	else if (value == 4096)
		img_file = "./pieces/xpm195/4096.xpm";
	else if (value == 8192)
		img_file = "./pieces/xpm195/8192.xpm";
	if (*img_file)
	{
		img = mlx_xpm_file_to_image(vars->mlx, img_file, &width, &height);
		mlx_put_image_to_window(vars->mlx, vars->win, img, (((tile % 4) * 200) + 5), (((tile / 4) * 200) + 5));
	}
}

void    refresh_screen(t_vars *vars)
{
	for (int i = 0; i < 16; i++)
	{
	   draw_tile(vars, i, vars->board[i]);
	}
}

int random_tile(int *board)
{
	int	i;
	int num_empty_tiles;
	int	*empty_tiles;

	num_empty_tiles = 0;
	for (int j = 0; j < 16; j++)
	{
		if(!board[j])
			num_empty_tiles++;
	}

	if (num_empty_tiles == 0)
		return(69);

	printf("Empty Tiles: %d\n", num_empty_tiles);
	empty_tiles = malloc((num_empty_tiles * sizeof(int)) + 1);

	i = 0;
	for (int j = 0; j < 16; j++)
	{
		if(!board[j])
				empty_tiles[i++] = j;
	}

	i = rand() % num_empty_tiles;
	i = empty_tiles[i];
	free(empty_tiles);
	printf("Tile: %d\n", i);
	return(i);
}