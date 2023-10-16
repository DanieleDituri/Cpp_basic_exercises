#include <iostream>
#include <cassert>
#include <string>
#include "roman.h"

void print_roman(int n){
    assert(n > 0 && n < 4000);
    std::cout << calc_roman(n) << std::endl;
}

std::string calc_roman(int n){
    std::string roman = "";

    
        while (n >= 1000){
            roman += "M";
            n -= 1000;
        }
        while (n >= 900){
            roman += "CM";
            n -= 900;
        }
        while (n >= 500){
            roman += "D";
            n -= 500;
        }
        while (n >= 400){
            roman += "CD";
            n -= 400;
        }
        while (n >= 100){
            roman += "C";
            n -= 100;
        }
        while (n >= 90){
            roman += "XC";
            n -= 90;
        }
        while (n >= 50){
            roman += "L";
            n -= 50;
        }
        while (n >= 40){
            roman += "XL";
            n -= 40;
        }
        while (n >= 10){
            roman += "X";
            n -= 10;
        }
        while (n >= 9){
            roman += "IX";
            n -= 9;
        }
        while (n >= 5){
            roman += "V";
            n -= 5;
        }
        while (n >= 4){
            roman += "IV";
            n -= 4;
        }
        while (n >= 1){
            roman += "I";
            n -= 1;
        }

    return roman;
}