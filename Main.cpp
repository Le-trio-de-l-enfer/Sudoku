#include <iostream>
#include "Sudoku.h"
#include "TestSudoku.h"

int main() {
    testSudoku::TestSudoku test;


    sudoku::Sudoku s1(1, 9);
    std::cout << s1 << std::endl;
    std::cout << '\n';

    sudoku::Sudoku s2(2, 16);
    std::cout << s2 << std::endl;
    std::cout << '\n';

    sudoku::Sudoku s3(3, 25);
    std::cout << s3 << std::endl;
    std::cout << '\n';



    //sudoku::Sudoku s4(4, 9);
    //std::cout << s4 << std::endl;
    std::cout << '\n';

    //sudoku::Sudoku s5(5, 9);
    //std::cout << s5 << std::endl;
    std::cout << '\n';

    //s3.resolve(0);
    //std::cout << s3 << std::endl;
    //std::cout << '\n';

    return 0;
}
