#include <iostream>

using namespace std;

// using namespace pluto;

int global = 0; // dato globale che ha vita = eseguibile

void f()
{
    int j = 0;
}

void g()
{
    static int x = 0; // dato globale a visibilità locale
}

void h()
{

    int *p = nullptr; // puntatore a memoria dinamica nello stack

    p = new int;
    *p = 100;

    // check se p == nullptr
    // uso p
    delete p;
    /*
    int j = *P;
    */

    *p = 200;
    // p = nullptr;
}

void m()
{
    int **pp = nullptr;

    p = new int *;

    delete p;
    p = nullptr;
}

void a()
{
    int *p = nullpttr;
    int n = 90;

    p = new int[n];

    *(p + 1) = 9; // ok

    p = p + 1; // no ok a causa della delete successiva

    delete[] p; // delete per gli array, tanti dati da uccidere
    p = nullptr;
}

namespace pluto
{
    int global;

    void a()
    {
    }
}

void funct(int i)
{
    // uso i
}

void funct_b(const int i)
{
}

void funct2(int *pi)
{
    int valore = *pi; // int valore = ii;

    *pi = 0; // ii = 0;
}

void funct2_b(const int *pi)
{
    int x = *pi;  // ok
    *pi = 0;      // Errore
    pi = nullptr; // ok
}

void funct4(int *pi, int sz)
{
}

void funct3(int &ri)
{
    ri = 10; // ii = 10;
}

void funct3_b(const int &ri)
{
    int x = ri; // ok
    ri = 0;     // Errore
}

int main(int argc, char *argv[])
{

    int ii = 100;

    funct(ii);
    funct(900);

    funct2(&ii);
    // ii = 0;

    funct3(ii);

    int array[10];
    funct4(array);

    /*
        int j = 0; // variabili/dati allocati sullo stack
        {
        int *p; // locale alle {}
        }
    */

    h();

    int j = pluto::global;

    return 0;
}