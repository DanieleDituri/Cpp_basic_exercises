#include <iostream>
#include <cassert>
#include <algorithm>

typedef unsigned int size_type; //<< Tipo he definisce la dimensione dell'array

/**
 * @brief Stampa i caratteri della string
 *
 * Funzione che stampa i caratteri della stringa C di input un carattere per riga.
 *
 * @param str puntatore alla string C di input
 *
 * @pre str != nullptr
 */
void stampa_caratteri(const char *str)
{
    assert(str != nullptr);

    while (*str != '\0')
    {
        std::cout << *str << std::endl;
        str++;
    }
}

/**
 * @brief Calcola la lunghezza della stringa
 *
 * Funzione che calcola la lunghezza di una stringa C
 *
 * @param str puntatore alla stringa C di input
 *
 * @return la lunghezza della stringa C senza terminatore
 *
 * @pre str!= nullptr
 */
size_type calcola_lunghezza(const char *str)
{
    assert(str != nullptr);

    size_type length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}

void inverti_stringa(char *str)
{
    assert(str != nullptr);
    int L = calcola_lunghezza(str);

    for (int i = 0 ; i < L / 2 ; ++i)
    {
        std::swap(str[i], str[L - i - 1]);
    }

}

char *copia_stringa(const char *str)
{
    assert(str != nullptr);
    int L = calcola_lunghezza(str);
    char *str2 = new char[L];
    for (int i = 0 ; i < L ; ++i)
    {
        str2[i] = str[i];
    }
    return str2;
}

char *concatena_stringhe(const char *str1, const char *str2)
{
    assert(str1 != nullptr && str2 != nullptr);
    int L1 = calcola_lunghezza(str1), L2 = calcola_lunghezza(str2);
    char *str3 = new char[L1 + L2];
    int i = 0;
    for(; i < L1 ; ++i)
    {
        str3[i] = str1[i];
    }
    for(; i < L1 + L2 ; ++i){
        str3[i] = str2[i - L1];
    }
    return str3;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        stampa_caratteri(argv[1]);
        std::cout << "La lunghezza della stringa " << argv[1]
                  << " è: " << calcola_lunghezza(argv[1]) << std::endl;
        inverti_stringa(argv[1]);
        std::cout << "La stringa invertita è: " << argv[1] << std::endl;
        char *copy = copia_stringa(argv[1]);
        std::cout << copy << " è una copia indipendente di " <<  argv[1] << std::endl;
        std::cout << concatena_stringhe(argv[1], argv[1]) << " è una concatenazione di " << argv[1] << std::endl;
    }

    return 0;
}