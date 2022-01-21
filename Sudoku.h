#include <string>
#include <vector>


#ifndef SUDOKU_H
#define SUDOKU_H

namespace sudoku {

  class Sudoku {

    //Declaration des variables
    private:
        int _lvl = 0;
        int _size = 9;
        std::vector< std::vector<int> > _grille;

        void generateGrid(int reste);
        void generateGrid2(int reste, int total);
        bool isPlaceable_row(int, int);
        bool isPlaceable_column(int, int);
        bool isPlaceable_square(int, int, int);
        bool isValid(int, int, int);
        bool isEmpty(int&, int&);
        int getDifficulty();

    public:
        Sudoku(int lvl, int size);
        bool resolve();
        std::vector< std::vector<int> > getGrille() { return _grille ;};
        int getSize() { return _size ;};


  };

      std::ostream& operator<<(std::ostream& os, Sudoku& sudoku);
      std::ostream& operator<<(std::ostream& os, std::vector< std::vector<int> >& sudoku);


}

#endif
