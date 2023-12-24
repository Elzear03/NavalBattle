#include "NavalBattle.h"



/**
 * @brief Allow the player to shoot at the computer board.
 *
 * This function allows the player to input coordinates (X, Y) and shoot at the computer's game board.
 * It validates the input, checks if the shot is acceptable, and updates the board accordingly.
 * Additionally, it provides feedback to the player about the result of the shot.
 *
 * @param board Pointer to the player's game board.
 * @param game Pointer to the game structure.
 *
 * @note The function exits with status 1 if either the board or game pointer is NULL.
 */


void gameTurnPlayer(Board* board, Game* game) {				//Allow the player to shoot at the computer board
	if (board == NULL || game == NULL){
	    	exit (1);
	}
	unsigned short X;
	unsigned short Y;
	printf("-----------------------\n");
	printf("Player turn\n");
	printf("Choose where to shoot\n");
	printf("X :\n");
	int result1 = scanf("%hu",&X);
	if (result1 !=1){
		exit(2);
	}
	printf("Y :\n");
	int result2 = scanf("%hu",&Y);
	if (result2 !=1){
		exit(2);
	}
	printf("-----------------------\n");
	while (X >= boardSize || Y >= boardSize || X<0 || Y<0 || ((board->matrix)[X][Y] != WATER && (board->matrix)[X][Y] != BOAT)){	//Looking if the shoot is acceptable
		printf("Choose not acceptable, retry\n");
		printf("Choose where to shoot\n");
		printf("X :\n");
		int result1 = scanf("%hu",&X);
		if (result1 !=1){
			exit(2);
		}
		printf("Y :\n");
		int result2 = scanf("%hu",&Y);
		if (result2 !=1){
			exit(2);
		}
	}
	if ((board->matrix)[X][Y] == WATER){
		printf("Splash\n");
		(board->matrix)[X][Y] = WATER_SHOT;
	}
	if ((board->matrix)[X][Y] == BOAT){
		printf("Touch\n");
		(board->matrix)[X][Y] = WRECK;
		for (int i=0; i<boatNumber; i++){
			if (!boatAlive(board, &(game->Boats[0][i])) && !(game->DeadBoats[0][i])){
				game->DeadBoats[0][i] = true;
				printf("Sunk\n");
			}
		}
	}
}
	
	
	
	
/**
 * @brief Allow the computer to shoot at the player board.
 *
 * This function simulates the computer's turn to shoot at the player's game board.
 * It generates random coordinates (X, Y) for the computer's shot, validates the shot,
 * and updates the player's board based on the result.
 * Additionally, it provides feedback to the player about the result of the computer's shot.
 *
 * @param board Pointer to the player's game board.
 * @param game Pointer to the game structure.
 *
 * @note The function exits with status 1 if either the board or game pointer is NULL.
 */	

	
void gameTurnComputer(Board* board, Game* game) {			//Allow the computer to shoot at the player board
	if (board == NULL || game == NULL){
	    	exit (1);
	}
	unsigned short X;
	unsigned short Y;
	printf("-----------------------\n");
	printf("Computer turn\n");
	printf("-----------------------\n");
	
	X = rand() % boardSize;
	Y = rand() % boardSize;
	
	while (X >= boardSize || Y >= boardSize || X<0 || Y<0 || ((board->matrix)[X][Y] != WATER && (board->matrix)[X][Y] != BOAT)){	//The computer will shoot randomly
		X = rand() % boardSize;
		Y = rand() % boardSize;
	}
	
	if ((board->matrix)[X][Y] == WATER){
		printf("Splash\n");
		(board->matrix)[X][Y] = WATER_SHOT;
	}
	if ((board->matrix)[X][Y] == BOAT){
		printf("Touch\n");
		(board->matrix)[X][Y] = WRECK;
		for (int i=0; i<boatNumber; i++){
			if (!boatAlive(board, &(game->Boats[1][i])) && !(game->DeadBoats[1][i])){
				game->DeadBoats[1][i] = true;
				printf("Sunk\n");
			}
		}
	}
}









