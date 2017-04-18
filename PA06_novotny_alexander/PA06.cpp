#include "PA06.h"

int main ()
{
    BinarySearchTree<int> test;

    test.add ( 5 );
    test.add ( 2 );
    test.add ( 7 );
    test.add ( 1 );
    test.add ( 4 );
    test.add ( 3 );
    test.add ( 6 );

    std::cout << test << std::endl << "Height: " << test.getHeight() << std::endl;

    test.preorderTraverse ( blah );

    BinarySearchTree<int> test2;

    test2.add ( 8 );
    test2.add ( 6 );
    test2.add ( 4 );
    test2.add ( 2 );
    test2.add ( 7 );

    std::cout << test2 << std::endl << "Height: " << test2.getHeight() << std::endl;

}

void blah ( int& ech )
{
    std::cout << ech << std::endl;
}