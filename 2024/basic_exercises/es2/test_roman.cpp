#include <iostream>
#include "roman.h"

int main(int argc, char* argv[])
{
    std::cout << "Inserisci un numero tra 1 e 3999" << std::endl;
    int n;
    std::cin >> n;

    while (n < 1 || n > 3999)
    {
        std::cout << "Inserisci un numero tra 1 e 3999" << std::endl;
        std::cin >> n;
    }

    print_roman(n);

    return 0;
}