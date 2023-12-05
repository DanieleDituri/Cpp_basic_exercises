#include <iostream>
#include <cassert>
#include <ostream>
#include <algorithm>
#include "dbuffer.h"

dbuffer::dbuffer() : _size(0), _buffer(nullptr) {}

dbuffer::dbuffer(size_type size) : _size(0), _buffer(nullptr)
{
    _buffer = new int[size];
    _size = size;
}

dbuffer::dbuffer(size_type size, int value) : _size(0), _buffer(nullptr)
{
    _buffer = new int[size];
    _size = size;
    for (size_type i = 0; i < _size; i++)
    {
        _buffer[i] = value;
    }
}

void dbuffer::print_buffer() const
{
    if (_buffer == nullptr)
    {
        std::cout << "Buffer is empty" << std::endl;
        assert(_buffer != nullptr);
    }

    std::cout << "[ ";
    for (size_type i = 0; i < _size - 1; i++)
    {
        std::cout << _buffer[i] << ", ";
    }
    std::cout << _buffer[_size - 1] << " ]" << std::endl
              << std::endl;
}

void dbuffer::fill_buffer()
{
    for (size_type i = 0; i < _size; i++)
    {
        std::cout << "Insert value for position " << i + 1 << ": ";
        std::cin >> _buffer[i];
    }
}

unsigned int dbuffer::get_size() const
{
    return _size;
}

int dbuffer::get_value(size_type index)
{
    assert(index >= 0 && index < _size);
    return *(_buffer + index); // or _buffer[index]
}

void dbuffer::set_value(size_type index, int value)
{
    assert(index >= 0 && index < _size);
    *(_buffer + index) = value; // or _buffer[index] = value
}

int &dbuffer::value(size_type index)
{
    assert(index >= 0 && index < _size);
    return *(_buffer + index); // or _buffer[index]
}

const int &dbuffer::value(size_type index) const
{
    assert(index >= 0 && index < _size);
    return *(_buffer + index); // or _buffer[index]
}

int &dbuffer::operator[](size_type index)
{
    assert(index >= 0 && index < _size);
    return *(_buffer + index); // or _buffer[index]
}

const int &dbuffer::operator[](size_type index) const
{
    assert(index >= 0 && index < _size);
    return *(_buffer + index); // or _buffer[index]
}

dbuffer::dbuffer(const dbuffer &pT)
{
    _size = pT._size;
    _buffer = new int[_size];
    for (size_type i = 0; i < _size; i++)
    {
        _buffer[i] = pT._buffer[i];
    }
}

dbuffer &dbuffer::operator=(const dbuffer &pT)
{
    if (this != &pT)
    {
        dbuffer tmp(pT);

        std::swap(_size, tmp._size);
        std::swap(_buffer, tmp._buffer);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &os, const dbuffer &pT)
{
    os << pT.get_size() << std::endl;
    for (unsigned int i = 0 ; i < pT.get_size() ; i++)
    {
        os << pT[i] << " ";
    }
    os << std::endl;

    return os;
}

dbuffer::~dbuffer(void)
{
    if (_buffer != nullptr)
    {
        delete[] _buffer;
    }
    _size = 0;
    _buffer = nullptr;
}