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
    return false;
}

void Game::cliInput(){
    for (Line line : hLines){
        std::cout << "Enter horizontal coins: ";
        std::cin >> line.coins;
        std::cout << '\n';
        std::cout << "Enter horizontal volts: ";
        std::cin >> line.volts;
        std::cout << '\n';
    }
    for (Line line : vLines){
        std::cout << "Enter vertical coins: ";
        std::cin >> line.coins;
        std::cout << '\n';
        std::cout << "Enter vertical volts: ";
        std::cin >> line.volts;
        std::cout << '\n';
    }
}

void Game::output(){
    for (Line line : hLines){
        for (Square* square : line.squares){
            std::cout << "  " << square->value << "  ";
        }
        std::cout << '(' << line.coins << '\\' << line.volts << ")\n";
    }
    for (Line line : vLines){
        std::cout << '(' << line.coins << '\\' << line.volts << ")";
    }
    std::cout << '\n';
}

int main(){
    Game game;
    game.output();
}