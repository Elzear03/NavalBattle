#include "NavalBattle.h"



/**
 * @brief Check if a player has won the game.
 *
 * This function checks if a player has won the game by verifying if all their boats have been sunk.
 *
 * @param board Pointer to the Board structure representing the game board.
 * @param boat Pointer to the array of Boat structures representing the player's boats.
 * @return Returns true if the player has won (all boats sunk); otherwise, returns false.
 *
 * @note The function exits with status 1 if either the board or boat pointer is NULL.
 */


bool win(Board* board, Boat* boat) {				//Look if a player won
	if (board == NULL || boat == NULL){
	 exit (1);
  	}
	for (int i=0; i<boatNumber; i++){
		if (boatAlive(board, &(boat[i]))){	//As long as there is still a boat, it means that this is still not win
			return false;
		}
	}
	return true;
}



