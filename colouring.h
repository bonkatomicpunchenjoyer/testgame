#include <iostream>
#include <string>
#include <functional>
/*
i recommend this palette:
	1 = red;
	2 = green;
	3 = dark yellow;
	4 = dark blue;
	5 = purple;
	6 = blue;
	7 = grey;
	8 = dark grey;
	9 = light red;
	10 = light green;
	11 = light yellow;
	12 = light blue;
	13 = light purple;
	14 = cyan;
	15 = white;
	16 = black;
	17 = very dark blue;
	18 = less very dark blue;
	19 = even less very dark blue;
	20 = contrast dark blue;
	21 = contrast blue;
	22 = mud green;
	23 = dark mud blue;
	24 = less dark mud blue;
	25 = contrast mud blue;
	26 = contraster contrast mud blue;
	27 = even more contraster contrast mud blue;
	28 = camouflage green;
	29 = forest green;
	30 = dark grass blue;
	31 = a lil bit dark grass blue;
	32 = very contrasting light blue.
sure, ANSI has 256 colours, but man, you think im going to write all that in a comment?
*/
void colour(int colour) {
	std::cout << "\x1b[38;5;" << colour << "m"; // guess this stuff is understandable. this is just outputting the ANSI code for the colour to be as it is planned to be
}
void bg_colour(int  colour) {
	std::cout << "\x1b[48;5;" << colour << "m"; // the same stuff as the one above but for background
}
void default_colour() {
	std::cout << "\x1b[0m"; // resetting the colour to default
}
void print_colour(int colorCode1, int colorCode2, const std::string& text) {
	colour(colorCode1); // setting foreground
	bg_colour(colorCode2); // setting background
	std::cout << text; // printing text
	default_colour(); // doing whatever it says, it's written what it's doing
}
void print_colour_foreground(int colorCode, const std::string& text) {
	colour(colorCode); // setting foreground
	std::cout << text; // printing text
	default_colour(); // im not gonna even explain this.
}
void print_colour_background(int colorCode, const std::string& text) {
	bg_colour(colorCode); // setting background
	std::cout << text; // printing text
	default_colour(); // ...
}
