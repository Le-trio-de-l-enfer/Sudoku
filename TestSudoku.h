#include <string>
#include <vector>


#ifndef TESTSUDOKU_H
#define TESTSUDOKU_H


namespace testSudoku {

  class TestSudoku {

    public:
      TestSudoku();
      bool testAffichageGrille();
      bool testIsPlaceableRow();
      bool testIsPlaceableCol();
      bool testIsPlaceableSquare();

  };

}

#endif
