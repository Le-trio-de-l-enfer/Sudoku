#include <string>
#include <vector>

#ifndef SUDOKU_H
#define SUDOKU_H

namespace sudoku {

  class Sudoku {

    //Declaration des variables
    private:
        int _lvl = 0; //niveau de difficulte de la grille
        int _size = 9; //taille de la grille (valeur racine carre)
        std::vector< std::vector<int> > _grille; //grille de sudoku
        std::vector< std::vector<int> > _grilleSoluce; //grille de sudoku complete

        void generateGrid(int reste); //Permet de generer la grille de sudoku en resolvant une grille vide puis en enlevant des cases
        void generateGrid2(int reste, int total); //Permet de generer une grille
        bool isValid(int, int, int); //Permet de savoir si une case respeste toute les conditions pour pouvoir ecrire un chiffre
        bool isEmpty(int&, int&); //Permet de savoir si la case donne en parametre est vide (0) ou non.
        int getDifficulty(); //Retourne le nombre de case a laisser suivant la difficulte

    public:
        Sudoku(int lvl, int size); //Constructeur en partant d'une grille vide
        Sudoku(std::vector< std::vector<int> > grille); //Constructeur en donnant une grille en parametre
        bool resolve(int position); //Permet de resoudre la grille
        void setSoluce(); //Permet de remplacer la grille a trou par la correction

        //Getters
        std::vector< std::vector<int> > getGrille() { return _grille ;};
        int getSize() { return _size ;};

        //Les fonctions ci-dessous doivent etre en priver normalement mais en public a cause du fichier de test
        bool isPlaceable_row(int, int); //Permet de verifier que l'on peut ecrire un nombre dans la ligne choisie
        bool isPlaceable_column(int, int); //Permet de verifier que l'on peut ecrire un nombre dans la colonne choisie
        bool isPlaceable_square(int, int, int); //Permet de verifier que l'on peut ecrire un nombre dans le carre choisie


  };

      //Surcharge d'operateur pour afficher la grille de sudoku
      std::ostream& operator<<(std::ostream& os, Sudoku& sudoku);


}

#endif
