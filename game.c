#include "game_2048.h"

int	key_press(int keycode, t_vars *vars)
{
	//printf("keycode: %d\n", keycode);

	if (keycode == UP_ARROW)
		move_tiles(vars, 1);
	else if (keycode == DOWN_ARROW)
		move_tiles(vars, 2);
	else if (keycode == LEFT_ARROW)
		move_tiles(vars, 3);
	else if (keycode == RIGHT_ARROW)
		move_tiles(vars, 4);
	
	refresh_screen(vars);
	return(0);
}

void	start_game(t_vars *vars)
{
	int	tile1;
	int	tile2;

	for (int i = 0; i < 16; i++)
		{
			vars->board[i] = 0;
		}
	tile1 = random_tile(vars->board);
	if (tile1 == 69)
		mlx_destroy_window(vars->mlx, vars->win);
	spawn_tile(vars, tile1);
	tile2 = random_tile(vars->board);
	if (tile2 == 69)
		mlx_destroy_window(vars->mlx, vars->win);
	spawn_tile(vars, tile2);
}

void	spawn_tile(t_vars *vars, int tile)
{
	if (rand() % 10 == 0)
			vars->board[tile] = 4;
	else
			vars->board[tile] = 2;
	draw_tile(vars, tile, vars->board[tile]);
}

void	move_tiles(t_vars *vars, int dir)
{
	int j;

	if (dir == 1) // UP
	{
		for (int i = 4; i < 16; i++)
		{
			j = i;
			if (vars->board[i])
			{
				while(!vars->board[j - 4] && j - 4 >= 0)
				{
					vars->board[j - 4] = vars->board[j];
					vars->board[j] = 0;
					j -= 4;
				}
				if (vars->board[j - 4] == vars->board[j] && j - 4 >= 0)
				{
					vars->board[j - 4] *= 2;
					vars->board[j] = 0;
				}
			}
		}
	}
	else if (dir == 2) // DOWN
	{
		for (int i = 11; i >= 0; i--)
		{
			j = i;
			if (vars->board[i])
			{
				while(!vars->board[j + 4] && j + 4 < 16)
				{
					vars->board[j + 4] = vars->board[j];
					vars->board[j] = 0;
					j += 4;
				}
				if (vars->board[j + 4] == vars->board[j] && j + 4 >= 0)
				{
					vars->board[j + 4] *= 2;
					vars->board[j] = 0;
				}
			}
		}
	}
	else if (dir == 3) // LEFT
	{
		for (int i = 1; i < 16; i++)
		{
			j = i;
			if (vars->board[i])
			{
				while(!vars->board[j - 1] && (j % 4))
				{
					vars->board[j - 1] = vars->board[j];
					vars->board[j] = 0;
					j--;
				}
				if (vars->board[j - 1] == vars->board[j] && (j % 4))
				{
					vars->board[j - 1] *= 2;
					vars->board[j] = 0;
				}
			}
		}
	}
	else if (dir == 4) // RIGHT
	{
		for (int i = 14; i >= 0; i--)
		{
			j = i;
			if (vars->board[i])
			{
				while(!vars->board[j + 1] && ((j + 1) % 4))
				{
					vars->board[j + 1] = vars->board[j];
					vars->board[j] = 0;
					j++;
				}
				if (vars->board[j + 1] == vars->board[j] && ((j + 1) % 4))
				{
					vars->board[j + 1] *= 2;
					vars->board[j] = 0;
				}
			}
		}
	}

	j = random_tile(vars->board);
	if (j == 69)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			printf("Game Over\n");
			exit(1);
		}
	spawn_tile(vars, j);
	printf("{ %d | %d | %d | %d }\n", vars->board[0], vars->board[1], vars->board[2], vars->board[3]);
	printf("{ %d | %d | %d | %d }\n", vars->board[4], vars->board[5], vars->board[6], vars->board[7]);
	printf("{ %d | %d | %d | %d }\n", vars->board[8], vars->board[9], vars->board[10], vars->board[11]);
	printf("{ %d | %d | %d | %d }\n", vars->board[12], vars->board[13], vars->board[14], vars->board[15]);
}