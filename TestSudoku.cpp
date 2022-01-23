#include "Sudoku.h"
#include "TestSudoku.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

namespace testSudoku{

  TestSudoku::TestSudoku(){
    this->testAffichageGrille();
    if(this->testIsPlaceableRow()) std::cout << "IsPlaceableRow is validated" << '\n';
    else std::cout << "IsPlaceableRow is not validated" << '\n';
    if(this->testIsPlaceableCol()) std::cout << "IsPlaceableCol is validated" << '\n';
    else std::cout << "IsPlaceableCol is not validated" << '\n';
    if(this->testIsPlaceableSquare()) std::cout << "IsPlaceableSqare is validated" << '\n';
    else std::cout << "IsPlaceableSqare is not validated" << '\n';
  }

  bool TestSudoku::testAffichageGrille() {
    std::srand(std::time(nullptr));

    std::vector< std::vector<int> > grille1 = std::vector< std::vector<int> > (9, std::vector<int> (9, 0)); //rempli un double tableau de size*size de 0
    sudoku::Sudoku s1(grille1);
    std::cout << s1 << '\n';

    std::vector< std::vector<int> > grille2 = std::vector< std::vector<int> > (9, std::vector<int> (9, std::rand()%9+1)); //rempli un double tableau de size*size d'entier aleatoire
    sudoku::Sudoku s2(grille2);
    std::cout << s2 << '\n';

    return true;

  }

  bool TestSudoku::testIsPlaceableRow() {
      bool res = true;

      std::vector< std::vector<int> > grille1 = {
        {1,2,3,4,5,6,7,8,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
      };

      sudoku::Sudoku s1(grille1);

      if (!s1.isPlaceable_row(9,0)) {
        res = false;
      }

      if (s1.isPlaceable_row(4,0)) {
        res = false;
      }

      for (size_t i = 1; i < 10; i++) {
        if (!s1.isPlaceable_row(i,1)) {
          res = false;
        }
      }

      return res;
  }

  bool TestSudoku::testIsPlaceableCol() {
      bool res = true;

      std::vector< std::vector<int> > grille1 = {
        {1,0,3,4,5,6,7,8,0},
        {2,0,0,0,0,0,0,0,0},
        {3,0,0,0,0,0,0,0,0},
        {4,0,0,0,0,0,0,0,0},
        {5,0,0,0,0,0,0,0,0},
        {6,0,0,0,0,0,0,0,0},
        {7,0,0,0,0,0,0,0,0},
        {8,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
      };

      sudoku::Sudoku s1(grille1);

      if (!s1.isPlaceable_column(9,0)) {
        res = false;
      }

      if (s1.isPlaceable_column(4,0)) {
        res = false;
      }

      for (size_t i = 1; i < 10; i++) {
        if (!s1.isPlaceable_column(i,1)) {
          res = false;
        }
      }

      return res;
}

  bool TestSudoku::testIsPlaceableSquare() {
      bool res = true;

      std::vector< std::vector<int> > grille1 = {
        {1,2,3,4,5,6,7,8,0},
        {4,0,6,0,0,0,0,0,0},
        {7,8,9,0,0,0,0,0,0},
        {4,0,0,0,0,0,0,0,0},
        {5,0,0,0,0,0,0,0,0},
        {6,0,0,0,0,0,0,0,0},
        {7,0,0,0,0,0,0,0,0},
        {8,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
      };

      sudoku::Sudoku s1(grille1);

      if (!s1.isPlaceable_square(5,1,1)) {
        res = false;
      }

      if (s1.isPlaceable_square(4,1,1)) {
        res = false;
      }

      for (size_t i = 1; i < 10; i++) {
        if (!s1.isPlaceable_square(i,8,8)) {
          res = false;
        }
      }

      return res;
  }
}
