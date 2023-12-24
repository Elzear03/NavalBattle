#include "NavalBattle.h"



/**
 * @brief Check if it is possible to place a boat at the specified position on the board.
 *
 * This function checks whether it is possible to place a boat at the specified position on the board.
 * It verifies the position's validity, checks for overlap with existing boats, and ensures the boat is surrounded by water.
 *
 * @param board Pointer to the Board structure representing the game board.
 * @param boat Pointer to the Boat structure representing the boat to be placed.
 * @return Returns true if the position is valid for placing the boat; otherwise, returns false.
 *
 * @note The function exits with status 1 if either the board or boat pointer is NULL.
 */


bool ValidPos(Board* board, Boat* boat) {			//Look if it is possible to place a boat at this position
    if (board == NULL || boat == NULL){
    	exit (1);
    }

    if (boat->horizontalPos < 0 || boat->verticalPos < 0 || boat->horizontalPos >= boardSize || boat->verticalPos >= boardSize) {
        return false;
    }
    if (boat->horizontalPos + boat->boatSize > boardSize && boat->orientation == HORIZONTAL) {			//Looking if there is already a boat there
    	return false;
    }
    if (boat->verticalPos + boat->boatSize > boardSize && boat->orientation == VERTICAL) {
    	return false;
    }
    
    if (boat->orientation == HORIZONTAL){
	 for (int i = 0; i < boat->boatSize; i++) {
	      if (board->matrix[boat->horizontalPos + i][boat->verticalPos] != WATER ) {
		   return false;
	      }
	      if (boat->verticalPos != (boardSize - 1)){
		      if (board->matrix[boat->horizontalPos + i][boat->verticalPos + 1] != WATER ) {		//Looking around the boat
			   return false;
	              }
	      }
	      if (boat->verticalPos != 0){
		      if (board->matrix[boat->horizontalPos + i][boat->verticalPos - 1] != WATER ) {
			   return false;
	              }
	      }
	 }
	 if (boat->horizontalPos + boat->boatSize != boardSize){
	 	if (board->matrix[boat->horizontalPos + boat->boatSize][boat->verticalPos] != WATER ) {
			   return false;
	        }
	 }
	 if (boat->horizontalPos != 0){
	 	if (board->matrix[boat->horizontalPos - 1][boat->verticalPos] != WATER ) {
			   return false;
	        }
	 }
	 
    }
    
    if (boat->orientation == VERTICAL){
	 for (int i = 0; i < boat->boatSize; i++) {
	      if (board->matrix[boat->horizontalPos][boat->verticalPos + i] != WATER ) {
		   return false;
	      }
	      if (boat->horizontalPos != (boardSize - 1)){
		      if (board->matrix[boat->horizontalPos + 1][boat->horizontalPos + i] != WATER ) {
			   return false;
	              }
	      }
	      if (boat->verticalPos != 0){
		      if (board->matrix[boat->horizontalPos - 1][boat->verticalPos + i] != WATER ) {
			   return false;
	              }
	      }
	 }
	 if (boat->verticalPos + boat->boatSize != boardSize){
	 	if (board->matrix[boat->horizontalPos][boat->verticalPos + boat->boatSize] != WATER ) {
			   return false;
	        }
	 }
	 if (boat->verticalPos != 0){
	 	if (board->matrix[boat->horizontalPos][boat->verticalPos - 1] != WATER ) {
			   return false;
	        }
	 }
    }
    
    return true;
}




/**
 * @brief Allow to place a boat on the board at a valid position.
 *
 * This function randomly places a boat on the board at a valid position.
 * It uses the `ValidPos` function to check the validity of the position and changes the boat's position until a valid one is found.
 *
 * @param board Pointer to the Board structure representing the game board.
 * @param boat Pointer to the Boat structure representing the boat to be placed.
 *
 * @note The function exits with status 1 if either the board or boat pointer is NULL.
 */



void placeBoat(Board* board, Boat* boat) {			//Allow to place boats if position valid
    if (board == NULL || boat == NULL){	
    	exit (1);
    }
   
    boat->horizontalPos = rand() % boardSize;
    boat->verticalPos = rand() % boardSize;
    if (rand() % 2 == 0){
       	boat->orientation = HORIZONTAL;
        } 
    else{
        boat->orientation = VERTICAL;
    	}
    while (!ValidPos(board, boat)){				//Change the position of the boat until it find a place
        boat->horizontalPos = rand() % boardSize;
        boat->verticalPos = rand() % boardSize;
        if (rand() % 2 == 0){
        	boat->orientation = HORIZONTAL;
        } 
        else{
        	boat->orientation = VERTICAL;
        }
    }

    for (int i = 0; i < boat->boatSize; i++) {
        if (boat->orientation == HORIZONTAL) {
            board->matrix[boat->horizontalPos + i][boat->verticalPos] = BOAT;		//When the position is find we place the boat
        } else {
            board->matrix[boat->horizontalPos][boat->verticalPos + i] = BOAT;
        }
    }
}
















