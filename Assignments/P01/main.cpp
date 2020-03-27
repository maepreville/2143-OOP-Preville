///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Mae-Jeanne Preville
// Email:            maejeanne.t.c.preville@gmail.com
// Label:            P01
// Title:            Card Game
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:
//        This code implements a card game of war. The game is played amongst
//        two players namely player 1 and player 2. After each deal, the winner
//        will be stated.
//
// Files:            
//     termio.h
//		 poker_game.hpp
//		 main.cpp
//       
/////////////////////////////////////////////////////////////////////////////////

#include "war_game.hpp"

using namespace std;

int main() {

	Term::IO io;

	Deck D(52);

	for (int i = 0;i < 50;i++) {
		D.Shuffle();
		D.Print(2, true);
		io << "Player 1   Player 2\n";

		Game::play();
		
		break;
		
		io << Term::sleep(200);
	}

	system("Pause");
	return 0;	
}

