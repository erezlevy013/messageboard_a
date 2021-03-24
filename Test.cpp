#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

ariel::Board board;
TEST_CASE("Good code") {
    board.post(1,0,Direction::Horizontal,"erez");
    board.post(0,2,Direction::Vertical,"LEVY");
    CHECK(board.read(1,0,Direction::Horizontal,4) == "erEz");
    CHECK(board.read(0,0,Direction::Horizontal,4) == "L");

    board.post(10,10,Direction::Horizontal,"sale");
    board.post(10,10,Direction::Vertical,"Bale");
    CHECK(board.read(10,10,Direction::Horizontal,4) == "Bale");
    CHECK(board.read(10,10,Direction::Vertical,4) == "Bale");

    board.post(100,100,Direction::Horizontal,"I LOVE YOU");
    board.post(100,107,Direction::Horizontal,"call: +97205088852");
    CHECK(board.read(100,100,Direction::Horizontal,24) == "I LOVE call: +97205088852");

    board.post(15,15,Direction::Horizontal,"I");
    board.post(15,17,Direction::Horizontal,"LOVE");
    board.post(15,22,Direction::Horizontal,"C++");
    CHECK(board.read(15,15,Direction::Horizontal,10) == "I LOVE C++");

    board.post(30,30,Direction::Vertical,"Real Madrid");
    board.post(30,30,Direction::Horizontal,"Ramos");
    CHECK(board.read(30,30,Direction::Horizontal,3) == "Ram");
    CHECK(board.read(30,30,Direction::Horizontal,5) == "Ramos");

    board.post(30,30,Direction::Horizontal,"Ronaldo");
    CHECK(board.read(30,30,Direction::Horizontal,7) == "Ronaldo");

    board.post(30,30,Direction::Horizontal,"Ramos");
    CHECK(board.read(30,30,Direction::Horizontal,7) == "Ramosdo");

    board.post(45,20,Direction::Horizontal,"win win win..");
    board.post(45,21,Direction::Horizontal,"ww");
    board.post(45,23,Direction::Horizontal,".");
    board.post(45,27,Direction::Horizontal,".co.il");
    CHECK(board.read(45,20,Direction::Horizontal,13) == "www.win.co.il");

    board.post(50,50,Direction::Vertical,"");
    CHECK(board.read(50,50,Direction::Horizontal,5) == "");
    CHECK(board.read(50,50,Direction::Vertical,3) == "");

    board.post(50,50,Direction::Horizontal,"0-0");
    CHECK(board.read(50,50,Direction::Horizontal,3) == "0-0");
    board.post(50,50,Direction::Horizontal,"@");
    board.post(50,52,Direction::Horizontal,"@");
    CHECK(board.read(50,50,Direction::Horizontal,3) == "@-@");
    
    board.post(70,50,Direction::Horizontal,"pass:******");
    CHECK(board.read(70,54,Direction::Horizontal,6) == "******");
    board.post(70,54,Direction::Horizontal,"123456");
    CHECK(board.read(70,50,Direction::Horizontal,11) == "pass:123456");

    board.post(200,50,Direction::Horizontal,"(5)*(2) = 10");
    CHECK(board.read(200,50,Direction::Horizontal,12) == "(5)*(2) = 10");
    board.post(200,51,Direction::Horizontal,"2");
    board.post(200,55,Direction::Horizontal,"5");
    CHECK(board.read(200,50,Direction::Horizontal,12) == "(2)*(5) = 10");
    board.post(200,51,Direction::Horizontal,"5");
    board.post(200,53,Direction::Horizontal,"+");
    CHECK(board.read(200,50,Direction::Horizontal,12) == "(5)+(5) = 10");

}

TEST_CASE("Bad code") {
   
    CHECK_THROWS(board.read(1,2,Direction::Horizontal,0));
   

    
}

