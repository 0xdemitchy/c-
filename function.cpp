#include "header.h"


House::House(Colour c, int m, bool s) : colour(c), members(m), status(c) {}
Player::Player() : name(""), house(House(Red, 0, false)) {}

void ConfigureGame(Player players[], int num_of_players){
	string color;
	int i, j;

	for(i = 0; i < num_of_players; i++){
		cout << "Enter the name of player " << i + 1 << ": "; 
		cin >> players[i].name;

		cout << "Enter the colour of house of player " << i + 1 << "(Red, Yellow, Green, Blue)";
		cin >> color;

		if (color == "Red" || color == "red"){
			players[i].house = House(Red, 4, false);
		} else if (color == "Yellow" || color == "yellow"){
			players[i].house = House(Yellow, 4, false);
		} else if (color == "Green" || color == "green"){
			players[i].house = House(Green, 4, false);
		} else if (color == "Blue" || color == "blue"){
			players[i].house = House(Blue, 4, false);
		} else {
			cout << "Enter a valid colour" << endl;
			i--;
			continue;
		}

		bool isColor = false;

		for (j = 0; j < i; j++){
			if (players[j].house.colour == players[i].house.colour){
				isColor = true;
				break;
			}
		}

		if (isColor){
			cout << "Color is already assigned, choose a different color." << endl;
			i--;
		}
}
}

void printResults(Player players[], int num_of_players){
	string color;
	cout << "Name \t House \t Member \n";

	for (int i = 0; i < num_of_players; i++){
		switch (players[i].house.colour) {
			case Colour::Red:
				color = "Red";
				break;
			case Colour::Yellow:
				color = "Yellow";
				break;
			case Colour::Blue:
				color = "Blue";
				break;
			case Colour::Green:
				color = "Green";
				break;
		}
		cout << players[i].name << " \t" << color << " \t" << players[i].house.members << endl;
	}
}
