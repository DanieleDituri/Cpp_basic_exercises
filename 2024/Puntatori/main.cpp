#include <iostream>

int main()
{
    int i1 = 100;

    int i2 = 200;

    int *ptr = nullptr;

    std::cout << i1 << std::endl;

    std::cout << &i1 << std::endl;
    std::cout << &i2 << std::endl;

    std::cout << &ptr << std::endl; // indirizzo di ptr

    std::cout << ptr << std::endl; // contenuo di ptr

    ptr = &i1;
    
    std::cout << *ptr << std::endl; // valore puntato da ptr

    ptr = &i2;

    ptr = ptr - 100; 

    std::cout << ptr << std::endl;

    return 0;
}