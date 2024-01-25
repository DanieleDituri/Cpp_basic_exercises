
/**
 * @file dbuffer.cpp
 * @brief Implementation file for the dbuffer class.
 */

#include <iostream>
#include <algorithm>
#include <cassert>
#include "dbuffer.h"

/**
 * @brief Default constructor for the dbuffer class.
 */
dbuffer::dbuffer() : _size(0), _buffer(nullptr)
{
#ifndef NDEBUG
    std::cout << "dbuffer::dbuffer()" << std::endl;
#endif
}

/**
 * @brief Constructor for the dbuffer class with size and value parameters.
 * @param size The size of the buffer.
 * @param value The initial value to fill the buffer with.
 */
dbuffer::dbuffer(unsigned int size, int value) : _size(0), _buffer(nullptr)
{
    _buffer = new int[size];
    _size = size;

    for (unsigned int i = 0; i < _size; i++)
    {
        _buffer[i] = value;
    }

#ifndef NDEBUG
    std::cout << "dbuffer::dbuffer(unsigned int size, int value)" << std::endl;
#endif
}

/**
 * @brief Copy constructor for the dbuffer class.
 * @param other The dbuffer object to be copied.
 */
dbuffer::dbuffer(const dbuffer &other) : _size(0), _buffer(nullptr)
{
    _buffer = new int[other._size];
    for (unsigned int i = 0; i < other._size; i++)
    {
        _buffer[i] = other._buffer[i];
    }
    _size = other._size;

#ifndef NDEBUG
    std::cout << "dbuffer::dbuffer(const dbuffer &other)" << std::endl;
#endif
}

/**
 * @brief Assignment operator for the dbuffer class.
 * @param other The dbuffer object to be assigned.
 * @return A reference to the assigned dbuffer object.
 */
dbuffer &dbuffer::operator=(const dbuffer &other)
{
    if (this != &other)
    {
        dbuffer tmp(other);
        std::swap(_size, tmp._size);
        std::swap(_buffer, tmp._buffer);
    }

#ifndef NDEBUG
    std::cout << "dbuffer::operator=(const dbuffer &other)" << std::endl;
#endif

    return *this;
}

/**
 * @brief Destructor for the dbuffer class.
 */
dbuffer::~dbuffer(void)
{
    delete[] _buffer;

    _buffer = nullptr;
    _size = 0;

#ifndef NDEBUG
    std::cout << "dbuffer::~dbuffer()" << std::endl;
#endif
}

unsigned int dbuffer::get_size() const
{
    return _size;
}

int dbuffer::get_value(unsigned int index) const
{
    assert(index < _size);
    return *(_buffer + index);
}

void dbuffer::set_value(unsigned int index, int value)
{
    assert(index < _size);
    *(_buffer + index) = value;
}

int &dbuffer::value(unsigned int index)
{
    assert(index < _size);
    return *(_buffer + index);
}

const int &dbuffer::value(unsigned int index) const
{
    assert(index < _size);
    return *(_buffer + index);
}

int &dbuffer::operator[](unsigned int index)
{
    assert(index < _size);
    return *(_buffer + index);
}

const int &dbuffer::operator[](unsigned int index)const
{
    assert(index < _size);
    return *(_buffer + index);
}

void dbuffer::print()
{
    std::cout << "Size: " << _size << std::endl;
    std::cout << "Buffer: ";
    for (unsigned int i = 0; i < _size; i++)
    {
        std::cout << _buffer[i] << " ";
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const dbuffer &db)
{
    os << "Size: " << db._size << std::endl;
    os << "Buffer: ";
    for (unsigned int i = 0; i < db.get_size(); i++)
    {
        os << db[i] << " ";
    }
    os << std::endl;

    return os;
}