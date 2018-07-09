#ifndef GAME_H
# define GAME_H

typedef struct game {
	int game_over;
	int current_player;
	char *player_pieces;
	char *board_pieces;
	unsigned int *bitboards;
} Game;

Game	*new_game(void);
void	start_game(Game *game);
void	end_game(Game *game);

#endif
