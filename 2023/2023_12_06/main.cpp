#include <iostream>
#include <cassert>

/*
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(double &a, double &b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

void swap(char &a, char &b)
{
    char tmp = a;
    a = b;
    b = tmp;
}
*/

// sobstitute the three functions above
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/*
template <typename T> T prova() {}

template <typename T> void prova2()
{
    T tmp;
}
*/

template <typename T, typename Q>
void set(T *array, unsigned int size, const Q &value)
{
    assert(array != nullptr);

    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = static_cast<T>(value);
    }
}

template <typename T, typename P>
void ordina(T *array, unsigned int size, P compare)
{
    unsigned int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (compare(array[i], array[j]))
                swap(array[i], array[j]);
        }
    }
}


bool compare_int(int a, int b)
{
    return a > b;
}

template <typename T>
void print(T *array, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
}

template <typename T> void prova(const T &param) {}

template <> void prova(const double &param) {}

void prova (const double &param) {}

int main()
{
    /*
    int a = 1, b = 2;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "explicit swap" << std::endl;
    swap<int>(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    double c = 1.1, d = 2.2;
    std::cout << "c = " << c << ", d = " << d << std::endl;

    std::cout << "implicit swap" << std::endl;
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;

    prova<char>();
    //prova<>(); error
    prova2<int*>();
    */

    int a[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 5; i++)
    {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "set on a" << std::endl;
    set(a, 5, 1);
    for (int i = 0; i < 5; i++)
    {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    char b[5] = {'a', 'a', 'a', 'a', 'a'};
    for (int i = 0; i < 5; i++)
    {
        std::cout << b[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "set on b" << std::endl;
    set(b, 5, 'b');
    for (int i = 0; i < 5; i++)
    {
        std::cout << b[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    set(a, 5, 2.7);

    int c[5] = {5, 4, 3, 2, 1};
    print(c, 5);

    ordina(c, 5, compare_int);
    print(c, 5);

    return 0;
}