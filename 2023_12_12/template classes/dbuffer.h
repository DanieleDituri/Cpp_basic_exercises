#ifndef DBUFFER_H
#define DBUFFER_H

#include <iostream>
#include <ostream>
#include <cassert>

template <typename T>
class dbuffer
{
public:
    typedef unsigned int size_type; ///< type for sizes
    typedef T value_type;           ///< type for values

private:
    size_type _size;
    value_type *_buffer;

public:
    dbuffer() : _size(0), _buffer(nullptr) {} // default constructor FONDAMENTALE 1

    explicit dbuffer(size_type size) : _size(0), _buffer(nullptr)
    {
        _buffer = new value_type[size];
        _size = size;
    } // constructor with size

    dbuffer(size_type size, value_type value) : _size(0), _buffer(nullptr)
    {
        _buffer = new value_type[size];

        try
        {
            for (size_type i = 0; i < _size; i++)
            {
                _buffer[i] = value;
            }
            _size = size;
        }
        catch (...)
        {
            delete[] _buffer;
            _buffer = nullptr;
            throw;
        }
    } // constructor with size and value

    void print_buffer() const
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
    } // print the buffer

    void fill_buffer()
    {
        for (size_type i = 0; i < _size; i++)
        {
            std::cout << "Insert value for position " << i + 1 << ": ";
            std::cin >> _buffer[i];
        }
    } // fill the buffer

    size_type get_size() const
    {
        return _size;
    } // get the size of the buffer Java style

    const value_type &get_value(size_type index) const
    {
        assert(index >= 0 && index < _size);
        return *(_buffer + index); // or _buffer[index]
    }                              // get the value at the index position Java style

    void set_value(size_type index, const value_type &value)
    {
        assert(index >= 0 && index < _size);
        *(_buffer + index) = value; // or _buffer[index] = value
    }                               // set the value at the index position Java style

    value_type &value(size_type index)
    {
        assert(index >= 0 && index < _size);
        return *(_buffer + index); // or _buffer[index]
    }                              // get and set the value at the index position C++ style

    const value_type &value(size_type index) const
    {
        assert(index >= 0 && index < _size);
        return *(_buffer + index); // or _buffer[index]
    }                              // get and set the value at the index position C++ style

    value_type &operator[](size_type index)
    {
        assert(index >= 0 && index < _size);
        return *(_buffer + index); // or _buffer[index]
    }                              // get and set the value at the index position C++ style

    const value_type &operator[](size_type index) const
    {
        assert(index >= 0 && index < _size);
        return *(_buffer + index); // or _buffer[index]
    }                              // get and set the value at the index position C++ style

    dbuffer(const dbuffer &pT)
    {
        try
        {
            for (size_type i = 0; i < _size; i++)
            {
                _buffer[i] = pT._buffer[i];
            }
        }
        catch (...)
        {
            delete[] _buffer;
            _buffer = nullptr;
            throw;
        }
    } // copy constructor FONDAMENTALE 3

    dbuffer<T> &operator=(const dbuffer &pT)
    {
        if (this != &pT)
        {
            dbuffer tmp(pT);

            std::swap(_size, tmp._size);
            std::swap(_buffer, tmp._buffer);
        }

        return *this;
    } // assignment operator FONDAMENTALE 4

    ~dbuffer(void)
    {
        if (_buffer != nullptr)
        {
            delete[] _buffer;
        }
        _size = 0;
        _buffer = nullptr;
    } // destructor FONDAMENTALE 2
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const dbuffer<T> &pT)
{
    os << pT.get_size() << std::endl;
    for (typename dbuffer<T>::size_type i = 0; i < pT.get_size(); i++)
    {
        os << pT[i] << " ";
    }
    os << std::endl;

    return os;
} // output operator

#endif