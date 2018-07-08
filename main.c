
#include <stdio.h>

void	pretty_print_board(int *bitboards)
{
	int bitmask = 1;
	int row_count = 0;

	while (bitmask != 0)
	{
		printf("\n%c | %c | %c \n", "ABC");
		if (row_count % 3 == 0)
		{
			putchar('\n');
		}
		printf("%d", (bitmask & bitboards[0]) ? 1 : 0);
		bitmask <<= 1;
		row_count++;
	}
}

void	place_piece(int position_number, int *bitboard)
{
	*bitboard = (*bitboard | (((int) 1) << (position_number - 1)));	
}

int	check_win_horizontal(int bitboard)
{
	return (0);
}

int	check_win_diag_left(int bitboard)
{
	return (0);
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

		if (check_win_horizontal(bitboard[current_player]) &
		  //check_win_verticle()   &
		  //check_win_diag_right() &
		    check_win_diag_left(bitboard[current_player]))
		{
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
