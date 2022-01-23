# TP6 C++ : Sudoku Solver

## Membres du groupe

  - Nicolas BENOIT (https://github.com/ballandilin)
  - Benjamin MILHET (https://github.com/Orchanyne)


Sujet propose par M. Ginhac (https://github.com/dginhac)

## Introdution
Ce TP a pour but de generer des grilles de Sudoku de taille N avec 5 niveaux de difficultes. A l'aide d'un algorithme de "backtracking", nous devons resoudre ces differentes grilles de sudoku. Nous avons plutot bien apprecie le premier TP que nous avons realiser et nous aimons realiser des defis, c'est pour cela que pour notre 2e TP, nous avons choisit le plus complexe. 


## Deroulement du TP
Pour ce projet, nous avons commencer par lister l'ensemble des tâche à réaliser puis nous nous sommes répartit le travail. Premierement, un personne s'occupait du generateur pendant que l'autre realisait les 3 tests pour verifier si un nombre peut etre dans une ligne, une colonne, ou un carre. Pour la realisation du solveur, nous avons reflechit a deux sur le meme PC pour son implementation. Pour finir, une personne c'est charge des niveaux de difficulte et une autre personne de la possibilite de choisir une taille de grille.


## Problemes rencontres
A travers ce TP, nous avons rencontrer plusieurs problemes :
  - La majorite des grilles generer n'etait pas resolvable, elles suivaient bien les regles pour ne pas qu'il y ai deux fois le meme chiffre dans la meme ligne, dans la meme colonne et dans la meme case, mais bloquait a un moment car aucun chiffre ne pouvait etre place sur une case.
  - Pour generer une grille, nous devons d'abord resoudre une grille vide, puis enlever un certains nombre de case suivant la difficulte demande.
  - Pour la generation des grilles superieur a 25*25 cases, le temps de resolution de la grille vide prend un temps exponetielle suivant le nombre de case et peut prendre plusieurs minute. Cela vient sans-doute de notre facon d'avoir implementer l'algorithme.


## Rendu final
### Rendu d'un sudoku 9*9
![alt text](https://github.com/Le-trio-de-l-enfer/Sudoku/blob/main/9.jpg?raw=true)

### Rendu d'un sudoku 16*16
![alt text](https://github.com/Le-trio-de-l-enfer/Sudoku/blob/main/16.jpg?raw=true)

### Rendu d'un sudoku 25*25
![alt text](https://github.com/Le-trio-de-l-enfer/Sudoku/blob/main/25.jpg?raw=true)


