#include <iostream>
#include <cassert>
#include "dbuffer.h"

int main()
{
    dbuffer<int> di;
    dbuffer<double> db;
    dbuffer<dbuffer<int>> ddi (10, dbuffer<int>(5));

    std::cout << di;

    return 0;
}