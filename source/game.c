#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "board.h"
#include "win.h"

Game *init_game(Game *game)
{
	game->bitboards = (BITBOARD *) malloc(sizeof(BITBOARD) * 2);
	game->board_pieces = (char *) malloc(sizeof(char) * 9);
	game->player_pieces = (char *) malloc(sizeof(char) * 2);
	
	strncpy(game->player_pieces, "XO", 2);	
	strncpy(game->board_pieces, "123456789", 9);

	game->bitboards[0] = 0;
	game->bitboards[1] = 0;

	game->current_player = 0;

	return (game);
}

Game	*new_game(void)
{
	Game *game = (Game *) malloc(sizeof(Game));

	return (init_game(game));
}

void	game_loop(Game *game)
{
	int position_number;	

	while (!game->game_over)
	{
		get_pieces_from_board(game->board_pieces, game->player_pieces, game->bitboards);
		pretty_print_board(game->board_pieces);

		printf("\nPlayer %d: Enter Position Number: ", game->current_player + 1);
		scanf("%d", &position_number);

		place_piece_on_board(position_number, &(game->bitboards[game->current_player]));

		if (0)
		{
			game->game_over = 1;
		}

		game->current_player ^= 1;
	}
}

void	start_game(Game *game)
{
	game_loop(game);
}

void	end_game(Game *game)
{
	free(game->board_pieces);
	free(game->player_pieces);
	free(game->bitboards);
	free(game);
}
