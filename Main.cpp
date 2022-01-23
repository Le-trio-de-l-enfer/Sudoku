#include <iostream>
#include "Sudoku.h"
#include "TestSudoku.h"
#include <cmath>

int main() {
    //testSudoku::TestSudoku test; //Class de test

    int lvl = 0;
    int size = 0;

    do {
      std::cout << "Choisir une difficulte entre 1 et 5 : " << '\n';
      std::cin >> lvl;
    } while(lvl < 1 || lvl > 5);

    do {
      std::cout << "Choisir la taille de la grille (9/16/25) : " << '\n';
      std::cin >> size;
    } while(sqrt(size) != std::floor(sqrt(size)));

    sudoku::Sudoku s1(lvl, size);
    std::cout << s1 << std::endl;
    std::cout << '\n';
    s1.setSoluce();
    std::cout << s1 << std::endl;
    std::cout << '\n';

    return 0;
}
