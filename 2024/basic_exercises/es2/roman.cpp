#include <iostream>
#include <string>
#include "roman.h"

void print_roman(int n)
{
    enum roman
    {
        I = 1,
        V = 5,
        X = 10,
        L = 50,
        C = 100,
        D = 500,
        M = 1000
    };
    std::string roman_numeral = "";

    while (n >= M)
    {
        roman_numeral += 'M';
        n -= M;
    }
    if (n >= 900)
    {
        roman_numeral += "CM";
        n -= 900;
    }
    if (n >= 500 && n < 900)
    {
        roman_numeral += 'D';
        n -= D;
    }
    if (n >= 400 && n <= 500)
    {
        roman_numeral += "CD";
        n -= 400;
    }
    while (n >= C)
    {
        roman_numeral += 'C';
        n -= C;
    }
    if (n >= 90)
    {
        roman_numeral += "XC";
        n -= 90;
    }
    if (n >= 50 && n < 90)
    {
        roman_numeral += 'L';
        n -= L;
    }
    if (n >= 40 && n <= 50)
    {
        roman_numeral += "XL";
        n -= 40;
    }
    while (n >= X)
    {
        roman_numeral += 'X';
        n -= X;
    }
    if (n >= 9)
    {
        roman_numeral += "IX";
        n -= 9;
    }
    if (n >= 5 && n < 9)
    {
        roman_numeral += 'V';
        n -= V;
    }
    if (n >= 4 && n <= 5)
    {
        roman_numeral += "IV";
        n -= 4;
    }
    while (n >= 1)
    {
        roman_numeral += 'I';
        n -= I;
    }
    std::cout << "il numero " << n << "in romano è:" << std::endl;
    std::cout << roman_numeral << std::endl;
}