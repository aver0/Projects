//
//  GridGame.h
//  GridGame
//
//  Created by Anh on 9/12/17.
//  Copyright © 2017 Anh. All rights reserved.
//

#ifndef GridGame_h
#define GridGame_h

#include <iostream>
#include <stdlib.h>
#include <string>

class GridGame {
public:
    GridGame() {
        gameBoard = new int*[boardRows];
        for(int i = 0; i < boardRows; i++) {
            gameBoard[i] = new int[boardColumns+1];
        }
        
        playerMoves = new char*[boardRows];
        for(int i = 0; i < boardRows; i++) {
            playerMoves[i] = new char[boardColumns+1];
        }
    }
    
    void playerMove() {
        int row{-1};
        int column{-1};
        int move{-1};
        
        std::cout << "Pick a box" << std::endl;
        std::cin >> move ;
        
        move = move - 1;
        if(move < 0 || move > 100) {
            std::cout << "Invalid choice: Choose between 1-100" << std::endl;
            std::exit(-1);
        }
        else {
            row = move / 10;
            column = move % 10;
        }
        
        if(playerMoves[row][column] == 'P') {
            std::cout << "You have already chosen this position. Choose a new one" << std::endl;
        }
        else {
            playerMoves[row][column] = 'P';
            checkMove(row, column);
        }
    }
    
    void checkMove(int row, int column) {
        if(gameBoard[row][column] == 1) {
            std::cout << "UH OH, YOU STEPPED ON A MINE!"
                      << "BOOOOOOM! YOU LOSE!"
                      << std::endl;
            revealGrid(row, column);
            std::exit(-2);
        }
        else {
            std::cout << "Good choice! You're one step closer!"
                      << std::endl;
        }
    }

    void drawCurrentGrid() {
        int currentColumn = 1;
        for(int i = 0; i < boardRows; i++) {
            for(int j = 0; j < boardColumns; j++) {
                if(playerMoves[i][j] != 'P') {
                    if(currentColumn + j < 10) {
                    std::cout << "[" << currentColumn + j << " ]";
                    }
                    else {
                    std::cout << "[" << currentColumn + j << "]";
                    }
                }
                else {
                    std::cout << "[" << playerMoves[i][j] << " ]";
                }
            }
            currentColumn += 10;
            std::cout << std::endl;
            
        }
    }
    
    void revealGrid(int row, int column) {
        for(int i = 0; i < boardRows; i++) {
            for(int j = 0; j < boardColumns; j++) {
                if(i == row and j == column) {
                    std::cout << "[ " << "X" << " ]";
                }
                else if(playerMoves[i][j] == 'P') {
                    std::cout << "[ " << "P" << " ]";
                }
                else {
                    std::cout << "[ " << gameBoard [i][j] << " ]";
                }
            }
            std::cout << std::endl;
        }
    }

    
    void fillBoard() {
        for(int i = 0; i < boardRows; i++) {
            for(int j = 0; j < boardColumns; j++ ) {
                if(std::rand() % 10 > 2) {
                    gameBoard[i][j] = 0;
                }
                else {
                    gameBoard[i][j] = 1;
                }
            }
        }
        gameBoard[0][0] = 0; //Start
        gameBoard[9][9] = 0; //Finish
    }

private:
    int boardRows{10};
    int boardColumns{10};
    int **gameBoard;
    char **playerMoves;
    int move;
};


#endif /* Header_h */
