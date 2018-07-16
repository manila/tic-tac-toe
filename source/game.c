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
	int moves = 0;
	int position_number;	


	while (!game->game_over)
	{
		get_pieces_from_board(game->board_pieces, game->player_pieces, game->bitboards);
		pretty_print_board(game->board_pieces);

		if (moves >= 9)
		{
			game->game_over = 1;
			printf("\n Board Full: Scratch! \n");
		}
		else
		{
			printf("\nPlayer %d: Enter Position Number: ", game->current_player + 1);
			scanf("%d", &position_number);
			moves++;


			if (valid_piece_placement(position_number, game->bitboards))
			{
				place_piece_on_board(position_number, &(game->bitboards[game->current_player]));
				
				if (check_win(game->bitboards[game->current_player]))
				{		
					get_pieces_from_board(game->board_pieces, game->player_pieces, game->bitboards);
					pretty_print_board(game->board_pieces);
					printf("\n Player %d Won!\n", game->current_player + 1);
					game->game_over = 1;
				}

				game->current_player ^= 1;
			}
			else
			{
				moves--;
				printf("\n Invalid Move: Try Again \n");
			}
		}
	
	}

	if (ask_to_play_again())
	{
		reset_game(game);
		start_game(game);		
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

void	reset_game(Game *game)
{
	game->bitboards[0] = 0;
	game->bitboards[1] = 0;
}

int	ask_to_play_again(void)
{
	printf("\nDo you want to play again? [Y/N]: \n");

	return (0);
}
