#include <iostream>
#include "template.hpp"

int main()
{
    int ia, ib;
    double da, db;
    char *pa, *pb;

    swap(ia, ib); // ok
    swap(da, db); // ok

    funct(ia, ib); // ok versione generica
    // funct(ia,db); //errore
    funct(pa, pb); // ok versione specilizzata

    funct2(ia, pb); // ok

    // funct3(ia); //errore
    funct3<bool>(ia); // ok T=int, Q=bool

    funct4<double>(); // ok Q=double
    funct4(); // ok Q=int

    int array[5] = {1, 2, 3, 4, 5};

    set_data(array, 5, 10);

    double result;

    somma s; // funtore che implementa la somma double+int
    result = sum_data(array, 5, 0.0, s);
    std::cout << result << std::endl;

    return 0;
}
