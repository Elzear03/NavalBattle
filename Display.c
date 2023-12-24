#include "NavalBattle.h"



/**
 * @brief Display the content of the game board.
 *
 * This function prints the content of the specified game board to the console.
 * Each cell is represented by a character indicating the state of the cell.
 *
 * @param board Pointer to the game board to display.
 *
 * @note The function exits with status 1 if the board pointer is NULL.
 */

void displayBoard(Board* board) {			//Show a board
    if (board == NULL){
    	exit (1);
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board->matrix[i][j] == WATER_SHOT) {
            	printf("o ");  				
            }
            if (board->matrix[i][j] == WATER) {
            	printf("~ ");  
            }
            if (board->matrix[i][j] == BOAT) {
            	printf("B ");  
            }
            if (board->matrix[i][j] == WRECK) {
            	printf("X ");  
            }
        }
        printf("\n");
    }
}



/**
 * @brief Display the content of the computer's game board (boats hidden).
 *
 * This function prints the content of the specified game board to the console,
 * hiding the location of the boats on the computer's board.
 *
 * @param board Pointer to the computer's game board to display.
 *
 * @note The function exits with status 1 if the board pointer is NULL.
 */

void displayComputerBoard(Board* board) {			//Show the computer board (with the boats hide)
    if (board == NULL){
    	exit (1);
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board->matrix[i][j] == WATER_SHOT) {
            	printf("o ");  				
            }
            if (board->matrix[i][j] == WATER) {
            	printf("~ ");  
            }
            if (board->matrix[i][j] == BOAT) {
            	printf("~ ");  
            }
            if (board->matrix[i][j] == WRECK) {
            	printf("X ");  
            }
        }
        printf("\n");
    }
}
