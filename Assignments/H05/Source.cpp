///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Mae-Jeanne Preville
// Email:            maejeanne.t.c.preville@gmail.com
// Label:            H05
// Title:            Playing Cards - Not Just Poker
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:
//        This code adds some improvements to the vector class written in the
//        previous lesson. I won't comment this file like the previous one. I will
//        simply comment the additions to our class.
//
// Files:            
//       termio.h
//		 poker_game.hpp
//		 Source.cpp
//
/////////////////////////////////////////////////////////////////////////////////

#include "poker_game.hpp"

int main() {

	Term::IO io;

	Deck D(52);


	for (int i = 0;i < 50;i++) {
		D.Shuffle();
		D.Print(5, true);
		io << Term::sleep(200);
	}

	return 0;
}
