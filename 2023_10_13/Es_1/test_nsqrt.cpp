#include <iostream>
#include <cmath>
#include "nsqrt.h"

int main(){
    double x = 0.0;
    std::cout << "Dare un valore reale positivo: ";
    std::cin >> x;

    double radix = nsqrt(x, 1e-3);

    std::cout << "Il valore di nsqrt(x) è: " << radix << std::endl;
    std::cout << "Il valore di std::sqrt(x) è: " << std::sqrt(x) << std::endl;

    return 0;
}