

int	game_loop(void)
{
	int game_over = 0;
	int current_player = 0;
	char player_piece[] = "XO";
	int bitboard[2];
	
	while (!game_over)
	{
		pretty_print_board(bitboard[0], bitboard[1]);
	
		printf("Player %d: Enter Desired Position Number: ", current_player + 1);
		scanf("%d", position);
	
		place_piece(position, &bitboard[player_piece], player_piece[current_player]);

		check_win_horizontal();
		//check_win_verticle();
		check_win_diag_left();
		//check_win_diag_right();
	}

	return (0);
}

int	main(void)
{
	game_loop();	

	return (0);
}
