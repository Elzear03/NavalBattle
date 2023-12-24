#include "NavalBattle.h"
#include <time.h> 



/**
 * @brief The main function that runs the battleship game.
 *
 * The function initializes the game, displays the initial game boards, and enters a loop where players
 * take turns shooting at each other's boards until there is a winner or a tie. It prints the result of the game
 * and frees the allocated memory before exiting.
 *
 * @return Returns 0 upon successful execution.
 */



int main(){
	
	srand(time(NULL));

	Game* game = malloc(sizeof(Game));
	
	
	
	initializeGame(game);
	
	printf("Computer board\n");
	displayComputerBoard(&(game->Boards[0]));
	printf("Player board\n");
	displayBoard(&(game->Boards[1]));
	
	
	while(!win(&(game->Boards[0]), game->Boats[0]) && !win(&(game->Boards[1]), game->Boats[1])){ //While there is no winner the game go on
		printf("-----------------------\n");
		
		gameTurnPlayer(&(game->Boards[0]), game);
	
		printf("Computer board\n");
		displayComputerBoard(&(game->Boards[0]));
		
		gameTurnComputer(&(game->Boards[1]), game);
		
		printf("Player board\n");
		displayBoard(&(game->Boards[1]));
	}
	if (win(&(game->Boards[0]), game->Boats[0]) && win(&(game->Boards[1]), game->Boats[1])){
		printf("TIE\n");
	}
	else if (win(&(game->Boards[0]), game->Boats[0])){
		printf("-----------------------\n");
		printf("WIN GG\n");
		printf("-----------------------\n");
	}
	else {
		printf("-----------------------\n");
		printf("LOOSE NT\n");
		printf("-----------------------\n");
		printf("Boats where :\n");
		displayBoard(&(game->Boards[0]));
		printf("-----------------------\n");
	}
	
	freeGameBoard(&(game->Boards[0]));
	freeGameBoard(&(game->Boards[1]));
	free(game);

	return 0;
}




