#include "PA06.h"

int main ()
{
    BinarySearchTree<int> test;
    BinarySearchTree<int> test2;
    std::vector<int> values;
    std::vector<int> added;
    std::vector<int> second_values;

    srand ( time ( NULL ) );

    for ( int i = 1; i <= 200; i++ )
    {
        values.push_back ( i );
    }

    for ( int i = 0; i < 100; i++ )
    {
        int randomIndex = rand () % values.size ();
        int value = values [ randomIndex ];
        test.add ( value );
        values.erase ( values.begin () + randomIndex );
        added.push_back ( value );
    }

    std::cout << test;

    std::cout << "First binary Tree Statistics:" << std::endl
        << "-----------------------------" << std::endl
        << "Height: " << test.getHeight () << std::endl
        << "Inorder Output: ";
    test.inorderTraverse ( blah );
    std::cout << std::endl << std::endl;

    for ( int i = 0; i < 10; i++ )
    {
        int randomChance = rand () % 10;
        int randomIndex;
        int value;
        if ( randomChance <= i )
        {
            randomIndex = rand () % added.size ();
            value = added [ randomIndex ];
            added.erase ( added.begin() + randomIndex );
        }
        else
        {
            randomIndex = rand () % values.size ();
            value = values [ randomIndex ];
            values.erase ( values.begin () + randomIndex );
        }

        test2.add ( value );
        second_values.push_back ( value );
    }

    std::cout << test2;

    std::cout << "Second binary Tree Statistics:" << std::endl
        << "-----------------------------" << std::endl
        << "Height: " << test2.getHeight () << std::endl
        << "Preorder Output:  ";
    test2.preorderTraverse ( blah );
    std::cout << std::endl << "Inorder Output:   ";
    test2.inorderTraverse ( blah );
    std::cout << std::endl << "Postorder Output: ";
    test2.postorderTraverse ( blah );
    std::cout << std::endl << std::endl;

    for ( int i = 0; i < second_values.size (); i++ )
    {
        test.remove ( second_values [ i ] );
    }

    std::cout << test;

    std::cout << "First binary Tree Statistics:" << std::endl
        << "-----------------------------" << std::endl
        << "Height: " << test.getHeight () << std::endl
        << "Number of nodes: " << test.getNumberOfNodes() << std::endl
        << "Inorder Output: ";
    test.inorderTraverse ( blah );
    std::cout << std::endl << std::endl;

    std::cout << "First tree cleared: " << test.isEmpty () << std::endl
        << "Second tree clared: " << test2.isEmpty () << std::endl << std::endl;

    std::cout << "Clearing..." << std::endl << std::endl;

    test.clear ();
    test2.clear ();

    std::cout << "First tree cleared: " << test.isEmpty () << std::endl
        << "Second tree clared: " << test2.isEmpty () << std::endl << std::endl;
}

void blah ( int& ech )
{
    std::cout << ech << " ";
}