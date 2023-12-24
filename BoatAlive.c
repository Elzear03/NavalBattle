#include "NavalBattle.h"	




/**
 * @brief Check if a boat is still alive on the board.
 *
 * This function determines whether a given boat is still alive on the specified game board.
 * A boat is considered alive as long as it has at least one untouched cell on the board.
 *
 * @param board Pointer to the game board.
 * @param boat Pointer to the boat to check.
 * @return Returns true if the boat is still alive, false otherwise.
 *
 * @note The function exits with status 1 if either the board or boat pointer is NULL.
 */

bool boatAlive(Board* board, Boat* boat) {			//Look if a boat is still alive
    if (board == NULL || boat == NULL){
	 exit (1);
    }
    if (boat->orientation == HORIZONTAL){
    	for (int i = 0; i < boat->boatSize; i++){
    		if (board->matrix[boat->horizontalPos + i][boat->verticalPos] == BOAT ) {	//As long as the boat still has a cell that is a not touched, he is alive
		   return true;
	        }
	}
    }
    else {
    	for (int i = 0; i < boat->boatSize; i++){
    		if (board->matrix[boat->horizontalPos][boat->verticalPos + i] == BOAT ) {
		   return true;
	        }
	}
    }
    return false;
}






