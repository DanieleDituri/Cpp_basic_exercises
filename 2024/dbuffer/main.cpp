/**
 * @file main.cpp
 * @brief This file contains the main function for testing the dbuffer library.
 */
#include <iostream>
#include "dbuffer.h"

int main(int argc, char *argv[])
{
    dbuffer::dynamic_buffer d;

    std::cout << "Test of print() after init()" << std::endl;
    dbuffer::init(d);
    dbuffer::print(d);
    std::cout << std::endl;

    std::cout << "Test of print() after allocate()" << std::endl;
    dbuffer::allocate(d);
    dbuffer::print(d);
    std::cout << std::endl;

    std::cout << "Test of print() after set()" << std::endl;
    dbuffer::set(d, 5);
    dbuffer::print(d);
    std::cout << std::endl;

    std::cout << "Test of clone()" << std::endl;
    dbuffer::dynamic_buffer d2;
    dbuffer::init(d2);
    dbuffer::copy(d, d2);
    dbuffer::print(d);
    dbuffer::print(d2);
    std::cout << std::endl;

    dbuffer::deallocate(d);
    dbuffer::deallocate(d2);

    return 0;
}