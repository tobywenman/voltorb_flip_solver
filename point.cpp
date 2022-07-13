#include "point.h"
#include <iostream>
#include <assert.h>

Game::Game(){
    int squareNum = 0;
    int hline = 0;
    for (Line &line : this->hLines){
        for (int i=0; i<5; i++){
            Square * squareP;
            line.squares[i] = new Square;
            squareP = line.squares[i];
            vLines[i].squares[hline] = squareP;
            squareP->value = squareNum;
            squareP->lines[0] = &line;
            squareP->lines[1] = &vLines[i];
            squareNum++;
        }
        hline++;
    }
}

bool Game::check(){
    for (Line line :hLines){
        int volts;
        int coins;
        int unknown;
        for (Square *square :line.squares){
            switch (square->state)
            {
            case Square::values::unknown:
                unknown++;
                break;
            case Square::values::one:
                coins+=1;
                break;
            case Square::values::two:
                coins+=2;
                break;
            case Square::values::three:
                coins+=3;
                break;
            case Square::values::volt:
                volts++;
                break;
            
            default:
                assert(!"invalid state");
                break;
            }
        }
    }
}


int main(){
    Game game;
    for (Line line : game.hLines){
        for (int i=0; i<5; i++){
            std::cout << line.squares[i]->value << ' ';
        }
        std::cout << '\n';
    }


}