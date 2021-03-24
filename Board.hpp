

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdexcept>
#include "Direction.hpp"

using namespace std;
using ariel::Direction;

namespace ariel
{
    class Board
    {
    private:
    
    public:
       Board();
        ~Board();
        void post(unsigned int, unsigned int, Direction, string);
        string read(unsigned int, unsigned int, Direction, unsigned int);
        void show();
        string str="";

    };
}  
    ariel::Board::Board()
    {

    }    
    ariel::Board::~Board()
    {
    }

    void ariel::Board::post(unsigned int x, unsigned int y, Direction d, string s)
    {
        
        return;
    }

    string ariel::Board::read(unsigned int x, unsigned int y, Direction d, unsigned int s)
    {  
        
        return str;
    }

    void ariel::Board::show()
    {
        return;
    }
    
#endif



   