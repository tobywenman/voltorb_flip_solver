#include "point.h"
#include <iostream>
#include <assert.h>
#include <fstream>
#include <sstream>
#include <string>

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

void Game::fileInput(std::string filename)
{
    file.open(filename);
    if (file.good()){
        for (Line &line :hLines){
            std::string string;
            std::getline(file, string);
            std::stringstream ss(string);

            for (Square *square :line.squares){
                char value;
                ss >> value;
                switch (value)
                {
                case '1':
                    square->state = Square::values::one;
                    break;
                case '2':
                    square->state = Square::values::two;
                    break;
                case '3':
                    square->state = Square::values::three;
                    break;
                case 'v':
                    square->state = Square::values::volt;
                    break;
                
                default:
                    break;
                }
                ss >> value;
            }
            std::cout << '\n';
        }
    }
}

bool Game::check(){
    for (Line &line :hLines){
        int volts=0;
        int coins=0;
        int unknown=0;
        int minUnknownCoin;

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
            if (coins == line.coins){
                minUnknownCoin = 0;
            }
            else{
                minUnknownCoin = 1+(line.coins - coins)/3;
            }

        }
        if (unknown - minUnknownCoin < 0)
            {
                std::cout << "to few unknown for coin\n";
                return false;
            }

            if (line.volts - volts > unknown - minUnknownCoin)
            {
                std::cout << "to few unknown for volt\n";
                return false;
            }
        std::cout << "unknown, volt, coin, line volt, line coin, minUnknown: " << unknown << ',' << volts << ',' << coins << ',' << line.volts << ',' << line.coins << ',' << minUnknownCoin << '\n';

    }
    for (Line &line :vLines){
        int volts=0;
        int coins=0;
        int unknown=0;
        int minUnknownCoin;

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
            if (coins == line.coins){
                minUnknownCoin = 0;
            }
            else{
                minUnknownCoin = 1+(line.coins - coins)/3;
            }
            
            if (unknown - minUnknownCoin < 0)
            {
                std::cout << "to few unknown for coin\n";
                return false;
            }

            if (line.volts - volts > unknown - minUnknownCoin)
            {
                std::cout << "to few unknown for volt\n";
                return false;
            }

        }
        std::cout << "unknown, volt, coin, line volt, line coin, minUnknown: " << unknown << ',' << volts << ',' << coins << ',' << line.volts << ',' << line.coins << ',' << minUnknownCoin << '\n';

    }
    return true;
}

void Game::cliInput(){
    for (Line &line : hLines){
        std::cout << "Enter horizontal coins: ";
        std::cin >> line.coins;
        std::cout << '\n';
        std::cout << "Enter horizontal volts: ";
        std::cin >> line.volts;
        std::cout << '\n';
    }
    for (Line &line : vLines){
        std::cout << "Enter vertical coins: ";
        std::cin >> line.coins;
        std::cout << '\n';
        std::cout << "Enter vertical volts: ";
        std::cin >> line.volts;
        std::cout << '\n';
    }
    std::cout << "hlines 0 coins: " << hLines[0].coins << '\n';
}

void Game::output(){
    for (Line line : hLines){
        for (Square* square : line.squares){
            std::cout << "  " << square->state << "  ";
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
    //game.cliInput();
    
    
    std::string board;
    std::cout << "enter filename: ";
    std::cin >> board;
    std::cout << '\n';
    game.cliInput();
    game.fileInput(board);
    game.output();
    std::cout << game.check() << '\n';
}