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

    for (int i = 0; i < L / 2; ++i)
    {
        std::swap(str[i], str[L - i - 1]);
    }
}

char *copia_stringa(const char *str)
{
    assert(str != nullptr);
    int L = calcola_lunghezza(str);
    char *str2 = new char[L];
    for (int i = 0; i < L; ++i)
    {
        str2[i] = str[i];
    }
    return str2;
}

char *concatena_stringhe(const char *str1, const char *str2)
{
    assert(str1 != nullptr && str2 != nullptr);

    size_type L1 = calcola_lunghezza(str1), L2 = calcola_lunghezza(str2);
    char *str3 = new char[L1 + L2];
    int i = 0;
    for (; i < L1; ++i)
    {
        str3[i] = str1[i];
    }
    for (; i < L1 + L2; ++i)
    {
        str3[i] = str2[i - L1];
    }
    return str3;
}

const char *cerca_stringa(const char *s1, const char *st)
{
    assert(s1 != nullptr && st != nullptr);

    size_type i, j;
    size_type L1 = calcola_lunghezza(s1), L2 = calcola_lunghezza(st);

    assert(L1 > 0 && L2 > 0 && L1 < L2);

    for (i = 0; i < L1 - L2 + 1; ++i)
    {
        for (j = 0; j < L2; ++j)
        {
            if (st[j] != s1[i + j])
                break;
        }
        if (j == L2)
            return s1 + i;
    }
    return nullptr;
}

char *cerca_stringa(char *s1, const char *st)
{
    /*
    assert(s1 != nullptr && st != nullptr);

    size_type i, j;
    size_type L1 = calcola_lunghezza(str1), L2 = calcola_lunghezza(str2);

    for (i = 0; i < L1 - L2 + 1; ++i)
    {
        for (j = 0; j < L2; ++j)
        {
            if (st[j] != s1[i + j])
                break;
        }
        if (j == L2)
            return s1 + i;
    }
    return nullptr;
    */
    // const char *result = cerca_stringa(static_cast<const char*>(s1), st);
    return const_cast<char *>(cerca_stringa(static_cast<const char *>(s1), st));
}

/**
 * @brief Sostituisce tutte le occorrenze di una sottostringa in una stringa con un'altra sottostringa.
 *
 * Questa funzione cerca la sottostringa `st` all'interno della stringa `s1` e la sostituisce con la stringa `s2`.
 * Questa operazione viene eseguita in tutte le occorrenze di `st` all'interno di `s1`.
 *
 * @param s1 La stringa in cui cercare e sostituire le occorrenze di `st`.
 * @param st La sottostringa da cercare e sostituire.
 * @param s2 La stringa con cui sostituire `st`.
 *
 * @pre `s1`, `st`, e `s2` devono essere puntatori validi e non dovrebbero essere `nullptr`.
 * @pre La lunghezza di `s1` (L1) deve essere maggiore di zero.
 * @pre La lunghezza di `st` (Lt) deve essere maggiore di zero.
 * @pre La lunghezza di `s1` (L1) deve essere minore della lunghezza di `st` (Lt).
 * @pre La lunghezza di `st` (Lt) deve essere uguale alla lunghezza di `s2` (L2).
 *
 * @note Questa funzione modifica direttamente la stringa `s1` per sostituire le occorrenze di `st` con `s2`.
 * @note La funzione termina quando non sono più presenti occorrenze di `st` in `s1`.
 */
void sovrascrivi_stringa(char *s1, const char *st, const char *s2)
{
    assert(s1 != nullptr && st != nullptr && s2!= nullptr);

    size_type L1 = calcola_lunghezza(s1), Lt = calcola_lunghezza(st), L2 = calcola_lunghezza(s2);

    assert(L1 > 0);
    assert(Lt > 0);
    assert(L1 < Lt);
    assert(Lt == L2);

    char *res = nullptr;
    res = cerca_stringa(s1, st);

    while(res != nullptr)
    {
        for(size_type i = 0 ; i < L2; ++i)
        {
            res[i] = s2[i];
        }
        if(res[Lt] == '\0') return;
        res = cerca_stringa(res + Lt, st);
    }
}

int main(int argc, char *argv[])
{
    if (argc > 3)
    {
        std::cout << "Stringa di partenza: " << argv[1] << std::endl;
        sovrascrivi_stringa(argv[1], argv[2], argv[3]);
        std::cout << "Nuova stringa: " << argv[1] << std::endl;
    }
    if (argc > 2)
    {
        char *result = nullptr;
        result = cerca_stringa(argv[1], argv[2]);
        if (result != nullptr)
        {
            std::cout << "La stringa " << argv[2] << " è presente nella stringa " << argv[1] << std::endl;
        }
    }
    if (argc > 1)
    {
        stampa_caratteri(argv[1]);
        std::cout << "La lunghezza della stringa " << argv[1]
                  << " è: " << calcola_lunghezza(argv[1]) << std::endl;
        inverti_stringa(argv[1]);
        std::cout << "La stringa invertita è: " << argv[1] << std::endl;
        char *copy = copia_stringa(argv[1]);
        std::cout << copy << " è una copia indipendente di " << argv[1] << std::endl;
        std::cout << concatena_stringhe(argv[1], argv[1]) << " è una concatenazione di " << argv[1] << std::endl;
    }

    return 0;
}