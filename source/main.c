#include "game.h"

int	main(void)
{
	Game *game = new_game();

	start_game(game);

	end_game(game);

	return (0);
}
