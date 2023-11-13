#include <iostream>
#include <cassert>
#include <ostream>
#include "dbuffer.h"

dbuffer::dbuffer() : _size(0), _buffer(nullptr) {}

dbuffer::dbuffer(size_type size) : _size(size)
{
    _buffer = new int[size];
}

dbuffer::dbuffer(size_type size, int value) : _size(size)
{
    _buffer = new int[size];
    for (size_type i = 0 ; i < _size ; i++)
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
    for (size_type i = 0 ; i < _size - 1 ; i++)
    {
        std::cout << _buffer[i] << ", ";
    }
    std::cout << _buffer[_size - 1] << " ]" << std::endl << std::endl;
}

void dbuffer::fill_buffer()
{
    for (size_type i = 0; i < _size; i++)
    {
        std::cout << "Insert value for position " << i + 1 << ": ";
        std::cin >> _buffer[i];
    }
}

dbuffer::dbuffer(const dbuffer &pT)
{
    _size = pT._size;
    _buffer = new int[_size];
    for (size_type i = 0 ; i < _size ; i++)
    {
        _buffer[i] = pT._buffer[i];
    }
}



dbuffer::~dbuffer()
{
    _size = 0;
    delete[] _buffer;
}