#include <iostream>
#include "nsqrt.h"

int main(int argc, char* argv[])
{
    std::cout << "Inserisci il numero di cui vuoi calcolare la radice quadrata: ";
    double x;
    std::cin >> x;

    std::cout << "Inserisci la tolleranza: ";
    double epsilon;
    std::cin >> epsilon;

    while (epsilon < 1)
    {
        std::cout << "La tolleranza deve essere maggiore di 0. Inserisci un'altra tolleranza: ";
        std::cin >> epsilon;
    }

    std::cout << "La radice quadrata di " << x << " vale: " << nsqrt(x, epsilon) << std::endl;

    return 0;
}