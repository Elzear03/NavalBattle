all : prog

prog : Initialization.o PlaceBoat.o Display.o Win.o GameTurn.o BoatAlive.o Main.o
	gcc -o prog Initialization.o PlaceBoat.o Display.o Win.o GameTurn.o BoatAlive.o Main.o


Initialization.o : Initialization.c
	gcc -o Initialization.o -c Initialization.c
	

PlaceBoat.o : PlaceBoat.c
	gcc -o PlaceBoat.o -c PlaceBoat.c
	

Display.o : Display.c
	gcc -o Display.o -c Display.c
	
	
Win.o : Win.c
	gcc -o Win.o -c Win.c

	
GameTurn.o : GameTurn.c
	gcc -o GameTurn.o -c GameTurn.c
	

BoatAlive.o : BoatAlive.c
	gcc -o BoatAlive.o -c BoatAlive.c


Main.o : Main.c
	gcc -o Main.o -c Main.c
	
	
	
clean :
	rm -rf *.o prog





