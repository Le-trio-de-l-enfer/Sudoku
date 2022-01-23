#include <string>
#include <vector>


#ifndef TESTSUDOKU_H
#define TESTSUDOKU_H


namespace testSudoku {

  class TestSudoku {

    public:
      TestSudoku();
      bool testAffichageGrille(); //tester l'affichage de la grille
      bool testIsPlaceableRow(); //test la fonction isPlaceableRow
      bool testIsPlaceableCol(); //test la fonction isPlaceableColumn
      bool testIsPlaceableSquare(); //test la fonction IsPlaceableSqare

  };

}

#endif
