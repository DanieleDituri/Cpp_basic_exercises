#include <iostream>

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
    int *p = nullptr;
    p = new int;
    *p = 100;

    // uso p

    delete p;
    *p = 200;
    p = nullptr;
}

void m()
{
    int **p = nullptr;

    p = new int *;

    delete p;
    p = nullptr;
}

void a()
{
    int *p = nullptr;
    int n = 90;

    p = new int[n];

    // uso p

    *(p + 1) = 9;
    p = p + 1;

    delte[] p; // delete array
    p = nullptr;
}

int main(int argc, char *argv[])
{
    int j = 0; // variabli/dati allocati sullo stack
    {
        int *p; // locale a {}
    }

    h();

    return 0;
}