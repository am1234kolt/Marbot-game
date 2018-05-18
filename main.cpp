#include <iostream>
#include "game.h"
int main() {

    std::cout << "\nSelect robot: \n\n1. Path Robot\n2. Manu Robot\n";
    auto choice{-1};
    while(!(std::cin >> choice));

    if (choice == 1 || choice == 2) {
        game l_game{choice};
        l_game.run();
    }
}