
#include <stdio.h>

void 	*get_player_pieces(char *player_pieces, int bitboard_x, int bitboard_o)
{
	int bitmask = 1;
	int position_number = 0;

	while (bitmask)
	{
		if (bitboard_x & bitmask)
		{
			player_pieces[position_number] = 'X';
		}
		else if (bitboard_o & bitmask)
		{
			player_pieces[position_number] = 'O';
		}

		position_number++;
		bitmask <<= 1; 
	}	
}

void	pretty_print_board(int *bitboard)
{
	char player_pieces[9] = "123456789";

	get_player_pieces(player_pieces, bitboard[0], bitboard[1]);

	printf("\n  %c | %c | %c ", player_pieces[0], player_pieces[1], player_pieces[2]);
	printf("\n ---|---|---");
	printf("\n  %c | %c | %c ", player_pieces[3], player_pieces[4], player_pieces[5]);
	printf("\n ---|---|---");
	printf("\n  %c | %c | %c\n", player_pieces[6], player_pieces[7], player_pieces[8]);
}


int	place_piece(int position_number, int *bitboard)
{
	if (((((int) 1) << (position_number - 1)) & *bitboard))
	{
		return (0);
	}
	else
	{
		(*bitboard |= (((int) 1) << (position_number - 1)));
		return (*bitboard | (((int) 1) << (position_number - 1)));
	}
}

int	check_win_horizontal(int bitboard)
{
	return ((bitboard >> 1) & (bitboard >> 2) & bitboard);
}

int	check_win_diag_left(int bitboard)
{
	return ((bitboard >> 4) & (bitboard >> 8) & bitboard);
}

void	game_loop(void)
{
	int game_over = 0;
	int current_player = 0;
	char player_piece[] = "XO";
	int bitboard[2] = {0, 0};
	int position_number;
	
	while (!game_over)
	{
		pretty_print_board(bitboard);
	
		printf("\nPlayer %d: Enter Desired Position Number: ", current_player + 1);
		scanf("%d", &position_number);

		place_piece(position_number, &bitboard[current_player]);

		if (check_win_horizontal(bitboard[current_player]) |
		  //check_win_verticle()   &
		  //check_win_diag_right() &
		    check_win_diag_left(bitboard[current_player]))
		{
			pretty_print_board(bitboard);
			printf("\nPlayer %d Won!\n", current_player + 1);
			game_over = 1;		
		}

		current_player = (~(current_player)) & ((int) 1);
	}
}

int	main(void)
{
	game_loop();	

	return (0);
}
