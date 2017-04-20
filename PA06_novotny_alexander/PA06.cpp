#include "PA06.h"

int main ()
{
    BinarySearchTree<int> test;
    std::vector<int> values;

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
    }

    int value;
    bool success;

    while ( true )
    {
        std::cout << test << std::endl
            << "Enter a value to remove: " << std::endl;

        std::cin >> value;

        if ( value == 0 )
        {
            break;
        }

        success = test.remove ( value );

        std::cout << "Removal " << ( success ? "Successful" : "Failed" ) << std::endl;
    }
    
}

void blah ( int& ech )
{
    std::cout << ech << std::endl;
}