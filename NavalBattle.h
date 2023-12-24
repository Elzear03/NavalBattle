#ifndef NavalBattle_h
	#define NavalBattle_h

	#include <stdio.h>
	#include <stdlib.h>

	#define boatNumber 5		//Represent the number of boat at each side
	#define boardSize 7		//Represent the size of each board
	
	#define bool unsigned short	//Define boolean
	#define true 1
	#define false 0
	
	




	typedef enum {
		WATER,           //Water don't hit by a shot
		WATER_SHOT,      //Water hit by a shot
		BOAT,            //Part of a boat
		WRECK            //Wreckage of a boat
	}Cell;




	typedef enum {
		HORIZONTAL,	      //Horizontal orientation
		VERTICAL	      //Vertical orientation
	}Orientation;




	typedef struct {
		unsigned short boatSize;        //Size of the boat
		unsigned short horizontalPos;   //Horizontal position
		unsigned short verticalPos;     //Vertical position
		Orientation orientation;        //Orientation
	}Boat;
		



	typedef struct {
		Cell** matrix;                  //Matrix
	}Board;


	typedef struct {
		Board Boards[2]; 	 		//Game boards for two players
        	Boat Boats[2][boatNumber];  		//Boats of the two players
       		bool DeadBoats[2][boatNumber];		//Dead boats of the two players
        }Game;




	void initializeBoat(Boat* boat, unsigned short size, unsigned short horizontalPos, unsigned short verticalPos, Orientation orientation); //Allow to create a boat
	
	bool boatAlive(Board* board, Boat* boat);            //Look if a boat is still alive
	
	bool win(Board* board, Boat* boat);		     //Look if a player won
	
	void initializeBoard(Board* board);		     //Allow to create a board
	
	bool ValidPos(Board* board, Boat* boat);	     //Look if it is possible to place a boat at this position
	
	void placeBoat(Board* board, Boat* boat);	     //Allow to place boats if position valid

	void initializeGame(Game* game);		     //Allow to create start the game
	
	void displayBoard(Board* board);		     //Show a board
	
	void displayComputerBoard(Board* board);	     //Show the computer board (with the boats hide)
	
	void freeGameBoard(Board* board);		     //Allow to free the allocated space of a board

	void gameTurnPlayer(Board* board, Game* game);	     //Allow the player to shoot at the computer board
	
	void gameTurnComputer(Board* board, Game* game);     //Allow the computer to shoot at the player board



#endif

