/**
 * @file main.cpp
 * @brief This file contains the main function of the program.
 *
 * The program takes a command-line argument and performs various operations on the string.
 * It demonstrates the usage of functions from the "stringhec" library.
 */

#include <iostream>
#include <cassert>
#include "stringhec.h"

/**
 * @brief The main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return 0 if the program executed successfully.
 */
int main(int argc, char *argv[])
{
    // assert(argc > 1);
    if (argc > 1)
    {
        std::cout << "Prova di stampa():" << std::endl;
        stampa(argv[1]);
        std::cout << std::endl;

        std::cout << "Prova di lunghzza():" << std::endl;
        std::cout << "La stringa " << argv[1] << " ha lunghezza "
                  << lunghezza(argv[1]) << std::endl;
        std::cout << std::endl;

        std::cout << "Prova di inverti():" << std::endl;
        std::cout << "La stringa " << argv[1] << " invertita è ";
        inverti(argv[1]); // non è una copia ma la stringa originale modificata
        std::cout << argv[1] << std::endl;
        std::cout << std::endl;
        inverti(argv[1]); // riporto la stringa originale

        std::cout << "Prova di clona():" << std::endl;
        char *clone = clona(argv[1]); // clone è una copia di argv[1]
        inverti(clone);               // modifico clone
        std::cout << "La stringa clone: " << clone << std::endl;
        std::cout << "È indipedente dalla stringa originale argv: "
                  << argv[1] << std::endl;
        delete[] clone;
        clone = nullptr;
        std::cout << std::endl;

        std::cout << "Prova di concatena():" << std::endl;
        char *concatenata = concatena(argv[1], "concatenata");
        std::cout << "La stringa concatenata è: " << concatenata << std::endl;
        delete[] concatenata;
        concatenata = nullptr;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Passare una stringa" << std::endl;
    }

    if(argc > 2)
    {
        std::cout << "Prova di cerca():" << std::endl;
        const char *t = cerca(argv[1], argv[2]);
        if(t != nullptr)
        {
            std::cout << "token trovato: " << t << std::endl;
        }
        else
        {
            std::cout << "token non trovato" << std::endl;
        }
    }
    else
    {
        std::cout << "Passare due stringhe" << std::endl;
    }

    return 0;
}