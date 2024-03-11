#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


enum Colour {Red, Yellow, Green, Blue};

struct House {
	Colour colour;
	int members;
	bool status;

	House(Colour c, int m, bool s);
};

struct Player{
	House house;
	string name;

	Player();
};

void ConfigureGame(Player players[], int num_of_players);
void printResults(Player players[], int num_of_players);

#endif
