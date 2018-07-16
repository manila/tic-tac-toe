#include "board.h"

int	check_win_horizontal(BITBOARD bitboard)
{
	return (bitboard & (bitboard >> 1) & (bitboard >> 2));
}

int	check_win_verticle(BITBOARD bitboard)
{
	return (bitboard & (bitboard >> 3) & (bitboard >> 6));
}

int	check_win_diag_right(BITBOARD bitboard)
{
	return ((bitboard & 0x111) == 0x111);
}

int	check_win_diag_left(BITBOARD bitboard)
{
	return ((bitboard & 0x54) == 0x54);
}

int	check_win(BITBOARD bitboard)
{
	return (check_win_horizontal(bitboard) ||
		check_win_verticle(bitboard) ||
		check_win_diag_right(bitboard) ||
		check_win_diag_left(bitboard));
}
