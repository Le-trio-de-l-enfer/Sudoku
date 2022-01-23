# TP6 C++ : Sudoku Solver

## Membres du groupe

  - Nicolas BENOIT (https://github.com/ballandilin)
  - Benjamin MILHET (https://github.com/Orchanyne)


Sujet proposé par M. Ginhac (https://github.com/dginhac)

## Introdution
Ce TP a pour but de générer des grilles de Sudoku de taille N avec 5 niveaux de difficulté. À l'aide d'un algorithme de "backtracking", nous devons résoudre ses différentes grilles de sudoku. Nous avons plutôt bien apprécie le premier TP que nous avons réalisé et nous aimons réaliser des défis, c'est pour cela que pour notre 2e TP, nous avons choisi le plus complexe. 


## Déroulement du TP
Pour ce projet, nous avons commencé par lister l'ensemble des tâches à réaliser puis nous nous sommes réparti le travail. Premièrement, une personne s'occupait du générateur pendant que l'autre réalisait les 3 tests pour vérifier si un nombre peut être dans une ligne, une colonne, ou une carre. Pour la réalisation du solveur, nous avons réfléchi à deux sur le même PC pour son implementation. Pour finir, une personne c'est charge des niveaux de difficulté et une autre personne de la possibilité de choisir une taille de grille.


## Problèmes rencontrés
À travers ce TP, nous avons rencontré plusieurs problèmes :
  - la majorité des grilles générées n'était pas resolvable, elles suivaient bien les règles pour qu'il n'y est pas deux fois le même chiffre dans la même ligne, dans la même colonne et dans la même case, mais bloquait a un moment car aucun chiffre ne pouvait être placer sur une case.
  - Pour générer une grille, nous devons d'abord résoudre une grille vide, puis enlever un certain nombre de cases suivant la difficulté demande.
  - Pour la génération des grilles supérieures à 25*25 cases, le temps de résolution de la grille vide prend un temps exponentiel suivant le nombre de case et peut prendre plusieurs minutes. Cela vient sans doute de notre façon d'avoir implementer l'algorithme.


## Rendu final
### Rendu d'un sudoku 9*9
![alt text](https://github.com/Le-trio-de-l-enfer/Sudoku/blob/main/img/9.png?raw=true)

### Rendu d'un sudoku 16*16
![alt text](https://github.com/Le-trio-de-l-enfer/Sudoku/blob/main/img/16.png?raw=true)

### Rendu d'un sudoku 25*25
![alt text](https://github.com/Le-trio-de-l-enfer/Sudoku/blob/main/img/25.png?raw=true)


