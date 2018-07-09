#include "board.h"

int	check_win_horizontal(BITBOARD bitboard)
{
	return (bitboard & 0);
}

int	check_win_verticle(BITBOARD bitboard)
{
	return (bitboard & 0);
}

int	check_win_diag_right(BITBOARD bitboard)
{
	return (bitboard & 0);
}

int	check_win_diag_left(BITBOARD bitboard)
{
	return (bitboard & 0);
}
