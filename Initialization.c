#include "NavalBattle.h"


/**
 * @brief Allow to create a boat.
 *
 * This function initializes a boat with the specified parameters, including its size, position, and orientation.
 *
 * @param boat Pointer to the Boat structure to initialize.
 * @param size Size of the boat.
 * @param horizontalPos Horizontal position of the boat on the board.
 * @param verticalPos Vertical position of the boat on the board.
 * @param orientation Orientation of the boat (HORIZONTAL or VERTICAL).
 */

void initializeBoat(Boat* boat, unsigned short size, unsigned short horizontalPos, unsigned short verticalPos, Orientation orientation) {	//Allow to create a boat
    boat->boatSize = size;
    boat->horizontalPos = horizontalPos;
    boat->verticalPos = verticalPos;
    boat->orientation = orientation;
}



/**
 * @brief Allow to create a board.
 *
 * This function initializes a game board with dimensions specified by the global constant `boardSize`.
 * Each cell of the board is initialized with the WATER state.
 *
 * @param board Pointer to the Board structure to initialize.
 *
 * @note The function exits with status 1 if the board pointer is NULL.
 */


void initializeBoard(Board* board) {		 //Allow to create a board
    if (board == NULL){
    	exit (1);
    }
    board->matrix = malloc(boardSize * sizeof(Cell*));
    if (board->matrix == NULL){
    	exit (2);
    }
    for (int i = 0; i < boardSize; i++) {
        board->matrix[i] = malloc(boardSize * sizeof(Cell));
        if (board->matrix[i] == NULL){
    		exit (3);
    }
        for (int j = 0; j < boardSize; ++j) {
            board->matrix[i][j] = WATER;  	//Place water on each cell
        }
    }
}






/**
 * @brief Allow to start the game by initializing boards and placing boats.
 *
 * This function initializes the game by creating two game boards (one for each player),
 * and placing boats on each board according to the specified rules.
 *
 * @param game Pointer to the Game structure to initialize.
 *
 * @note The function exits with status 1 if the game pointer is NULL.
 */


void initializeGame(Game* game) {			//Allow to create start the game
    if (game == NULL){
    	exit (1);
    }
    for (int i = 0; i < 2; i++) {
        initializeBoard(&(game->Boards[i]));
        for (int j = 0; j < boatNumber; j++) {
            int l = j % 4;						//We limit the boat maximum size to four
            if (l == 0){
            	l = 1;
            }
            (game->Boats[i][j]).boatSize = l;
            placeBoat(&(game->Boards[i]), &(game->Boats[i][j]));
            game->DeadBoats[i][j] = false;				//We indicate that the boat is alive
            
        }
    }
}



/**
 * @brief Allow to free the allocated space of a game board.
 *
 * This function frees the allocated memory for a game board, releasing resources.
 *
 * @param board Pointer to the Board structure to free.
 *
 * @note The function exits with status 1 if the board pointer is NULL.
 */



void freeGameBoard(Board* board) {				//Allow to free the allocated space of a board
    if (board == NULL){
    	exit (1);
    }
    for (int i = 0; i < boardSize; i++) {
        free(board->matrix[i]);			//We need to free each line
    }
    free(board->matrix);
}










