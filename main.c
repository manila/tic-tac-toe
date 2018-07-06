
#include <stdio.h>

void	place_piece(int position_number, int *bitboard)
{
	bitboard = (bitboard | (((int) 1) << (position_number - 1)));	
}

void	game_loop(void)
{
	int game_over = 0;
	int current_player = 0;
	char player_piece[] = "XO";
	int bitboard[2];
	int position_number;
	
	while (!game_over)
	{
		pretty_print_board(bitboard[0], bitboard[1]);
	
		printf("\nPlayer %d: Enter Desired Position Number: ", current_player + 1);
		scanf("%d", &position_number);
	
		place_piece(position, &bitboard[current_player]);

		if (check_win_horizontal() &
		  //check_win_verticle()   &
		 //check_win_diag_right()  &
		    check_win_diag_left())
		{
			printf("\nPlayer %d Won!\n", current_player + 1);
			game_over = 1;		
		}
	}
}

int	main(void)
{
	game_loop();	

	return (0);
}
