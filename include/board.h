#ifndef BOARD_H
# define BOARD_H

//type definition BITBOARD as int
typedef unsigned int BITBOARD;

/*
Print board to standard output with fancy ASCII grid 
given both player x and player o boards.
*/
void	pretty_print_board(char *board_pieces);

//Return a new board (individual player board) with a piece in desired position.
void	place_piece_on_board(int position_number, BITBOARD *bitboard);

char 	*get_pieces_from_board(char *board_pieces, char *player_pieces, BITBOARD *bitboards);

int	valid_piece_placement(int positions_number, BITBOARD *bitboard);

unsigned int	board_is_full(BITBOARD *bitboards);
#endif
