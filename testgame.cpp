#include <iostream>
#include "colouring.h"
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

// as you can see, it's windows only. i'd like a commit that would port it though. so im sorry my fellow penguinoids!
enum space {
	nothing,
	player,
	apple,
	wall
};
// just a enum that defines the whole map
void clear() {
	system("cls"); // again, something that makes this unavailable for anything except Shitdows
}
void collidecheck(space gamespace[16][16], int playerpos[2], int applepos[2], int &score) {
	if (playerpos[0] == applepos[0] && playerpos[1] == applepos[1]) {
		gamespace[applepos[0]][applepos[1]] = space::nothing; // setting the apple position to space::nothing as there is literally nothing. the player ate it
		applepos[0] = rand() % (16-1) + 1; // setting the apple x to a random position from 0 to 15
		applepos[1] = rand() % (16-1) + 1; // setting the apple y to a random position from 0 to 15
		score++; // adding some score
		gamespace[applepos[0]][applepos[1]] = space::apple; // putting an apple to the random location it made there ^^^
	}
}
void render(space gamespace[16][16], int score) {
	colour(11); // colouring the text below this comment to Light Yellow
	std::cout << "W - UP; S - DOWN; A - LEFT; D - RIGHT; Q - QUIT." << std::endl;
	print_colour(11,11, " _________________"); // drawing the upper border
	for (int i = 0; i < 16; i++) { // going through the whole map's Y
		if (i == 0) std::cout << std::endl;
		for (int u = 0; u < 16; u++) { // going through the whole map's X
			if (u == 0) print_colour_background(11, "|"); // drawing the left border
			if (gamespace[u][i] == space::player) { // drawing the player if theres a player
				print_colour_background(12, " "); // drawing
			}
			else if (gamespace[u][i] == space::wall) { // drawing a wall that never exists right now if theres a wall
				print_colour_background(7, " "); // drawing
			}
			else if (gamespace[u][i] == space::apple) { // drawing an apple if theres an apple
				print_colour_background(9, " "); // drawing
			}
			else { // drawing space::nothing if there's anything else
				print_colour_background(10, " ");
			}
			if (u == 15) print_colour_background(11, "|"); // drawing the right border
		}
		std::cout << "\n"; // printing out the new line so the game won't be a one line mess
	}; 
	print_colour(11,11, "|________________|\n"); // drawing the bottom border
	colour(11); // drawing the text below in color 11(they are documented in colouring.h btw)
	std::cout << "Score: " << score << "	Made by bonkatomicpunchenjoyer aka vlad" << std::endl; // writing the score and... idk, me???
}
void keycheck(char key, int playerpos[2], space gamespace[16][16]) {
	// checking some keys thru _getch()
	gamespace[playerpos[0]][playerpos[1]] = space::nothing; // setting the current player position to space::nothing
	if (key == 'a' && playerpos[0] > 0) { // if key that was pressed is A and player's position won't make him go out of bounds. the same is below, right before Q
		playerpos[0]--; // decreasing player's x by 1 symbol
	}
	else if (key == 'd' && playerpos[0] < 15) {
		playerpos[0]++; // adding 1 symbol to player's x
	}
	else if (key == 'w' && playerpos[1] > 0) {
		playerpos[1]--; // reducing 1 symbol from player's y
	}
	else if (key == 's' && playerpos[1] < 15) {
		playerpos[1]++; // plusing 1 symbol to player's y
	}
	else if (key == 'q') { // if key that was pressed is Q
		exit(0); // quitting with error code 0
	}
	gamespace[playerpos[0]][playerpos[1]] = space::player;
	
}
int main() {
	space gamespace[16][16] = { {} }; // making a gamespace
	for (int i = 0; i < 16; i++) {
		for (int u = 0; u < 16; u++) {
			gamespace[i][u] = space::nothing; // making everything to space::nothing, documented better in testfile.map
		}
	}
	int playerpos[2] = {0, 0}; // player's position
	int applepos[2] = { 15, 15 }; // apple's position
	int score = 0; // score
	gamespace[0][0] = space::player; // position of the player edited in gamespace to space::player
	gamespace[15][15] = space::apple; // position of the apple edited in gamespace to space::apple
	while (true) {
		clear(); // clearing the console so it won't be a mess (yes pingunoids, I just called it a console, not a terminal)
		render(gamespace, score); // render the whole game to be honest
		collidecheck(gamespace, playerpos, applepos, score); // check the collide of player and apple and add 1 to player's score
		keycheck(_getch(), playerpos, gamespace); // check key's that were pressed
		Sleep(100); // limiting fps to 100 
	}
	return 0; // returning error code 0
}
