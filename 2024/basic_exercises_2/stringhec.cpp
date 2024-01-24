/**
 * @file stringhec.cpp
 * @brief Implementation of string manipulation functions.
 */

#include <iostream>
#include <cassert>
#include <algorithm>
#include "stringhec.h"

void stampa(const char *str)
{
    assert (str != nullptr);

    while(*str != '\0')
    {
        std::cout << *str << std::endl;
        str++;
    }
}

unsigned int lunghezza(const char *str)
{
    assert (str != nullptr);

    const char *end = str;

    while(*end != '\0')
    {
        ++end;
    }

    return end - str;
}

void inverti(char *str)
{
    assert (str != nullptr);

    int L = lunghezza(str);

    for (int i = 0 ; i < L/2 ; ++i)
    {
        std::swap(str[i], str[L-i-1]);
    }
}

char *clona(const char *str)
{
    assert (str != nullptr);

    char *clone = new char[lunghezza(str) + 1];

    for (int i = 0 ; i < lunghezza(str) + 1 ; ++i)
    {
        clone[i] = str[i];
    }

    return clone;
}

char *concatena(const char *s1, const char *s2)
{
    assert (s1 != nullptr && s2 != nullptr);

    int L1 = lunghezza(s1);
    int L2 = lunghezza(s2);

    char *out = new char[L1 + L2 + 1];

    for (int i = 0 ; i < L1 ; ++i)
    {
        out[i] = s1[i];
    }

    for (int i = 0 ; i < L2 + 1 ; ++i)
    {
        out[L1 + i] = s2[i];
    }

    return out;
}

/**
 * @brief Checks if a token is found in a string.
 * 
 * This function compares two strings character by character until either the end of the token string or the end of the input string is reached.
 * 
 * @param s The input string to search in.
 * @param st The token string to search for.
 * @return True if the token is found in the string, false otherwise.
 */
bool token_trovato(const char* s, const char* st)
{
    while((*s == *st) && (*s != '\0'))
    {
        ++s;
        ++st;
    }
    
    return (*st == '\0');
}

const char *cerca(const char *s1, const char *st)
{
    assert (s1 != nullptr && st != nullptr);

    bool trovato = false;
    for (int i = 0 ; i < lunghezza(s1) ; ++i)
    {
        trovato = token_trovato(s1 + i, st);
        if (trovato)
        {
            return s1 + i;
        }
    }

    return nullptr;
}