#include <iostream>
#include "roman.h"

int main(){
    int roman = 0;

    std::cout << "Inserire un numero tra 1 e 3999: ";
    std::cin >> roman;

    print_roman(roman);
}