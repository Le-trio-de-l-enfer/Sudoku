#include "Sudoku.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>

namespace sudoku {


    Sudoku::Sudoku(int lvl, int size) : _lvl(lvl), _size(size) {
        _grille = std::vector< std::vector<int> > (_row, std::vector<int> (_column, 0)); //rempli un double tableau de 9*9 de 0
        std::srand(time(nullptr));
        //this->generateGrid2(40, 40);
        this->resolve();
        this->generateGrid(this->getDifficulty());

    }


  void Sudoku::generateGrid2(int reste, int total) {
        int N = reste;
        if (N > 0) {
          int row = std::rand()%9;
          int col = std::rand()%9;
          int num = std::rand()%9+1;
          //std::cout << num << '\n';
          if (_grille[row][col] == 0) {
            if (isValid(num, row, col)) {
                _grille[row][col] = num;
                N--;
            }
          }
          this->generateGrid2(N, total);
        }

    }


    void Sudoku::generateGrid(int reste) {
        int N = reste;
        if (N > 0) {
          int row = std::rand()%9;
          int col = std::rand()%9;
          if (_grille[row][col] != 0) {
              _grille[row][col] = 0;
              N--;
          }
          this->generateGrid(N);
        }
    }

    int Sudoku::getDifficulty() {
      int res = 0;
      switch (_lvl) {
        case 1:
          res = _size*_size*0.3;
          break;
        case 2:
          res = _size*_size*0.4;
          break;
        case 3:
          res = _size*_size*0.5;
          break;
        case 4:
          res = _size*_size*0.6;
          break;
        case 5:
          res = _size*_size*0.7;
          break;
        default:
          res = _size*_size*0.3;
          break;
      }

      return res;
    }

    bool Sudoku::resolve() {
        std::srand(time(nullptr));
        int row, col;

        if (!isEmpty(row, col)) {
            return true;
        }

        std::vector<int> v;
        for (size_t i = 1; i < 10; i++) v.push_back(i);

        std::shuffle(v.begin(), v.end(), std::mt19937(std::random_device()()));

        for(int & num : v){
        //for (size_t num = 0; num < _size; num++) {
            if (isValid(num, row, col)) {
                _grille[row][col] = num;
                if (resolve()) {
                    return true;
                }
                _grille[row][col] = 0;
            }
        }
        return false;
    };


    bool Sudoku::isValid(int n, int x, int y) {
          bool res = false;
          if (_grille[x][y] == 0) {
            res = isPlaceable_row(n, x) && isPlaceable_column(n, y) && isPlaceable_square(n, x , y);
          }
          return res;
    }

    bool Sudoku::isEmpty(int &row, int &col) {
        for (row = 0; row < _row; row++) {
            for (col = 0; col < _column; col++) {
                if (_grille[row][col] == 0) {
                    return true;
                }
            }
        }
        return false;
      }


    bool Sudoku::isPlaceable_row(int n, int x) {
        bool res = true;
        for (int row = 0; row < _row; row++) {
            if (_grille[x][row] == n) res = false;
        }
        return res;
    }

    bool Sudoku::isPlaceable_column(int n, int y) {
        bool res = true;
        for (int col = 0; col < _column; col++){
            if (_grille[col][y] == n) res = false;
        }
        return res;
    }

    bool Sudoku::isPlaceable_square(int n, int x, int y) {
        std::cout << _grille << '\n';
        std::cout << "/* message */" << '\n';
        std::cout << x << '\n';
        std::cout << y << '\n';
        std::cout << "/* message */" << '\n';
        bool res = true;
        int _x = x - x%3;
        int _y = y - y%3;
        for (int row = _x; row < _x+3; row++) {
          for (int col = _y; col < _y+3; col++) {
            std::cout << n << '\n';
            std::cout << row << '\n';
            std::cout << col << '\n';
            std::cout << '\n';

            if (_grille[row][col] == n){
              std::cout << "---------------------------" << '\n';
               return false;
            }
          }
        }
        std::cout << "Next" << '\n';
        std::cout << '\n';

        return true;
    }

    std::ostream& operator<<(std::ostream& os, Sudoku& sudoku) {
        auto g = sudoku.getGrille();
        for (size_t i = 0; i < 9; i++)
        {
            if (i%3 == 0 && i != 0) {
                for (size_t n = 0; n < 16; n++)
                {
                    os << "__";
                }
                os << std::endl;
                os << std::endl;
            }
            for (size_t j = 0; j < 9; j++)
            {
                if (!(j%3) && j != 0) {
                    os << " | ";
                }

                os << " ";
                if (g.at(i).at(j) == 0) {
                    os << "\x1B[91m0\033[0m";
                } else {
                    os << g.at(i).at(j);
                }

                os << " ";

            }

            os << "" << std::endl;

        }
        return os;
    }

    std::ostream& operator<<(std::ostream& os, std::vector< std::vector<int> >& sudoku) {
        auto g = sudoku;
        for (size_t i = 0; i < 9; i++)
        {
            if (i%3 == 0 && i != 0) {
                for (size_t n = 0; n < 16; n++)
                {
                    os << "__";
                }
                os << std::endl;
                os << std::endl;
            }
            for (size_t j = 0; j < 9; j++)
            {
                if (!(j%3) && j != 0) {
                    os << " | ";
                }

                os << " ";
                if (g.at(i).at(j) == 0) {
                    os << "\x1B[91m0\033[0m";
                } else {
                    os << g.at(i).at(j);
                }
                os << " ";

            }

            os << "" << std::endl;

        }
        return os;
    }

}
