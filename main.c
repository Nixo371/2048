#include "game_2048.h"

int	main(void)
{
	t_vars	vars;

	srand(time(NULL));

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 805, 805, "2048");

	start_game(&vars);
	mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);

	mlx_loop(vars.mlx);
}