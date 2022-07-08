#include "point.h"
#include <iostream>

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


int main(){
    Game game;
    // for (Line line : game.hLines){
    //     for (int i=0; i<5; i++){
    //         std::cout << line.squares[i]->value << ' ';
    //     }
    //     std::cout << '\n';
    // }

    for(Line *line : game.hLines[2].squares[2]->lines){
        for (Square *square : line->squares){
            std::cout << square->value << '\n';
        }
    }
}