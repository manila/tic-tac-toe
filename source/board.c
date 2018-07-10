#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "game.h"

void place_piece_on_board(int position_number, BITBOARD *bitboard)
{
	unsigned int bitmask = 1;
	
	bitmask <<= (position_number - 1);

	*bitboard |= bitmask;
}

char	*get_pieces_from_board(char *board_pieces, char *player_pieces, BITBOARD *bitboards)
{

	unsigned int bitmask = 1;
	int position_number = 0;

	while (position_number < 9)
	{
		if (bitboards[0] & bitmask)
		{
			board_pieces[position_number] = player_pieces[0];
		}
		else if (bitboards[1] & bitmask)
		{
			board_pieces[position_number] = player_pieces[1];
		}
		
		position_number++;
		bitmask <<= 1;
	}


	return (board_pieces);
}

void	pretty_print_board(char *player_pieces)
{
	printf("\n  %c | %c | %c ", player_pieces[0], player_pieces[1], player_pieces[2]);
	printf("\n ---|---|---");
	printf("\n  %c | %c | %c ", player_pieces[3], player_pieces[4], player_pieces[5]);
	printf("\n ---|---|---");
	printf("\n  %c | %c | %c\n", player_pieces[6], player_pieces[7], player_pieces[8]);
}

int	valid_piece_placement(int position_number, BITBOARD bitboard)
{
	return (0);
}
