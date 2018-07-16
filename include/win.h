#ifndef WIN_H
# define WIN_H

/* 
These functions return a truth value (greater than 0) 
if there are three set bits in a row
*/

int	check_win(BITBOARD bitboard);
int	check_win_horizontal(BITBOARD bitboard);
int	check_win_verticle(BITBOARD bitboard);
int	check_win_diag_right(BITBOARD bitboard);
int	check_win_diag_left(BITBOARD bitboard);

#endif
