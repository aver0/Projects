//
//  main.cpp
//  GridGame
//
//  Created by Anh on 9/12/17.
//  Copyright © 2017 Anh. All rights reserved.
//

#include <iostream>
#include "GridGame.h"

int main(int argc, const char * argv[]) {
    GridGame game1;
    game1.fillBoard();
    while(true) {
        game1.playerMove();
        game1.drawCurrentGrid();
    }
    

}
