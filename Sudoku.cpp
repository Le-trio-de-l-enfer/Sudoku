#include "Sudoku.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>

namespace sudoku {


    Sudoku::Sudoku(int lvl, int size) : _lvl(lvl), _size(size) {
        _grille = std::vector< std::vector<int> > (_size, std::vector<int> (_size, 0)); //rempli un double tableau de size*size de 0
        std::srand(std::time(nullptr));
        //this->generateGrid2(550,300);
        this->resolve(0);
        this->generateGrid(this->getDifficulty());

    }

    Sudoku::Sudoku(std::vector< std::vector<int> > grille) : _grille(grille) {
        _size = _grille.at(0).size();
        std::srand(std::time(nullptr));
        _lvl = 0;

    }
    void Sudoku::generateGrid2(int reste, int total) {
            int N = reste;
            if (N > 0) {
              int row = std::rand()%_size;
              int col = std::rand()%_size;
              int num = std::rand()%(_size+1);
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
          int row = std::rand()%_size;
          int col = std::rand()%_size;
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

    bool Sudoku::resolve(int position) {

        if (position == _size*_size) return true;
        int row = position/_size, col = position%_size;

        if (!isEmpty(row, col)) return resolve(position+1);
        std::vector<int> v;
        for (size_t i = 1; i < _size+1; i++) v.push_back(i);

        std::shuffle(v.begin(), v.end(), std::mt19937(std::random_device()()));

        for(int num : v){
            if (isValid(num, row, col)) {
                _grille[row][col] = num;

                if (resolve(position+1)) return true;
                _grille[row][col] = 0;
            }
        }
        return false;
    }

    bool Sudoku::isValid(int n, int x, int y) {
          if (_grille[x][y] == 0) {
            if (isPlaceable_row(n, x) && isPlaceable_column(n, y) && isPlaceable_square(n, x , y)) return true;
          }
          return false;
    }

    bool Sudoku::isEmpty(int &row, int &col) {
        if (_grille[row][col] == 0) {
          return true;
        }
        return false;
      }


    bool Sudoku::isPlaceable_row(int n, int x) {
        for (int row = 0; row < _size; row++) {
            if (_grille[x][row] == n) return false;
        }
        return true;
    }

    bool Sudoku::isPlaceable_column(int n, int y) {
        for (int col = 0; col < _size; col++){
            if (_grille[col][y] == n) return false;
        }
        return true;
    }

    bool Sudoku::isPlaceable_square(int n, int x, int y) {
        int nb = (int)sqrt(_size);

        int _x = x-(x%nb);
        int _y = y-(y%nb);

        for (int row = _x; row < _x+nb; row++) {
          for (int col = _y; col < _y+nb; col++) {
            if (_grille[row][col] == n) return false;
          }
        }

        return true;
    }

    std::ostream& operator<<(std::ostream& os, Sudoku& sudoku) {
        auto g = sudoku.getGrille();
        for (size_t i = 0; i < sudoku.getSize(); i++)
        {
            if (i%((int)sqrt(sudoku.getSize())) == 0 && i != 0) {
                for (size_t n = 0; n < sudoku.getSize()*2.3; n++)
                {
                    os << "__";
                }
                os << std::endl;
                os << std::endl;
            }
            for (size_t j = 0; j < sudoku.getSize(); j++)
            {
                if (!(j%((int)sqrt(sudoku.getSize()))) && j != 0) {
                    os << " | ";
                }

                os << " ";
                if (g.at(i).at(j) < 10) {
                  os << " ";
                }
                if (g.at(i).at(j) == 0) {
                    os << "\x1B[91m0\033[0m";
                    //os << "0";
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
        for (size_t i = 0; i < 25; i++)
        {
            if (i%((int)sqrt(25)) == 0 && i != 0) {
                for (size_t n = 0; n < 50; n++)
                {
                    os << "__";
                }
                os << std::endl;
                os << std::endl;
            }
            for (size_t j = 0; j < 25; j++)
            {
                if (!(j%((int)sqrt(25))) && j != 0) {
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
