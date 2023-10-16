#include <iostream>
#include <cassert>
#include "date.h"

int main(){
    int day1, month1, year1, day2, month2, year2;

    std::cout << "Inserisci la prima data:" << std::endl;
    std::cout << "Anno: ";
    std::cin >> year1;
    assert(year1 > 0);
    std::cout << "Mese: ";
    std::cin >> month1;
    assert(month1 > 0 && month1 < 13);
    std::cout << "Giorno: ";
    std::cin >> day1;
    assert(day1 > 0 && day1 < 32);
    if((month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11) && day1 == 31){
        while(day1 > 30 || day1 < 1){
            std::cout << "Il giorno inserito non è valido. Inserisci un nuovo giorno:" << std::endl;
            std::cin >> day1;
        }
    }
    if(month1 == 2  && day1 > 29){
        if(year1 % 4 == 0){
            while(day1 > 29 || day1 < 1){
            std::cout << "Il giorno inserito non è valido. Inserisci un nuovo giorno:" << std::endl;
            std::cin >> day1;
        }
        }
        while(day1 > 28 || day1 < 1){
            std::cout << "Il giorno inserito non è valido. Inserisci un nuovo giorno:" << std::endl;
            std::cin >> day1;
        }
    }

    std::cout << "Inserisci la seconda data:" << std::endl;
    std::cout << "Anno: ";
    std::cin >> year2;
    assert(year2 > 0);
    std::cout << "Mese: ";
    std::cin >> month2;
    assert(month2 > 0 && month2 < 13);
    std::cout << "Giorno: ";
    std::cin >> day2;
    assert(day2 > 0 && day2 < 32);
    if((month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) && day2 == 31){
        while(day2 > 30 || day2 < 1){
            std::cout << "Il giorno inserito non è valido. Inserisci un nuovo giorno:" << std::endl;
            std::cin >> day2;
        }
    }
    if(month2 == 2  && day2 > 29){
        if(year2 % 4 == 0){
            while(day2 > 29 || day2 < 1){
            std::cout << "Il giorno inserito non è valido. Inserisci un nuovo giorno:" << std::endl;
            std::cin >> day2;
        }
        }
        while(day2 > 28 || day2 < 1){
            std::cout << "Il giorno inserito non è valido. Inserisci un nuovo giorno:" << std::endl;
            std::cin >> day2;
        }
    }

    int diff = date_difference(year1, month1, day1, year2, month2, day2);

    if(diff == -1)
        std::cout << "La prima data è superiore alla seconda" << std::endl;
    else
        std::cout << "La differenza tra i due giorni è: " << diff << std::endl;

    return 0;
}