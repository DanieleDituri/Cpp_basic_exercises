#include <iostream>
#include <string>
#include "ops.h"

int main(){
/*
    std::cout << "Hello world" << std::endl;

    std::string s;

    std::cout << "Inserisci messaggio: ";
    std::cin >> s;
    std::cout << "Hai inserito: " << s << std::endl;

    double n = 0;

    std::cout << "Inserisci Numero: ";
    std::cin >> n;
    std::cout << "Hai inserito: " << n << std::endl;

    int i;
    unsigned int ui;

    short int si;
    long int li;

    long double num = 0;
    float f;
    char c;
    
    bool b;


    std::cout << sizeof(int) << std::endl;

    stampa();
*/

    int test = 1000;
    int *pi = nullptr;
    pi = &test;

    std::cout << "Contenuto di test: " << test << std::endl;
    std::cout << "indirizzo di test: " << &test << std::endl;
    std::cout << "Contenuto di pi: " << pi << std::endl;
    std::cout << "Indirizzo di pi: " << &pi << std::endl;

    int test2 = 999;
    pi = &test2;
    std::cout << "Contenuto del valore puntato: " << *pi << std::endl;

    *pi = 100;
    std::cout << "Contenuto di test2: " << test2 << std::endl;

    int *pi2 = pi;

    float *pf = nullptr;
    pf = pi;

    pi = pi + 200;

    pi2 - pi;
    pi2 + pi; //errore

    pi[1] = 90; // *(pi + 1) = 90

    return 0;
}