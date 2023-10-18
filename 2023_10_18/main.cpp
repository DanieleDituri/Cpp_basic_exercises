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

int main(int argc, char *argv[])
{
    int j = 0; // variabli/dati allocati sullo stack
    {
        int *p; // locale a {}
    }

    h();

    return 0;
}