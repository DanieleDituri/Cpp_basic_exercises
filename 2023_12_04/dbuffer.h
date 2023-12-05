#ifndef DBUFFER_H
#define DBUFFER_H

#include <ostream>

class dbuffer
{
public:
    typedef unsigned int size_type;

private:
    size_type _size;
    int *_buffer;

public:
    dbuffer(); // default constructor FONDAMENTALE 1

    explicit dbuffer(size_type size); // constructor with size

    dbuffer(size_type size, int value); // constructor with size and value

    void print_buffer() const; // print the buffer

    void fill_buffer(); // fill the buffer

    size_type get_size() const; // get the size of the buffer Java style

    int get_value(size_type index); // get the value at the index position Java style

    void set_value(size_type index, int value); // set the value at the index position Java style

    int &value(size_type index); // get and set the value at the index position C++ style

    const int &value(size_type index) const; // get and set the value at the index position C++ style

    int &operator[](size_type index); // get and set the value at the index position C++ style

    const int &operator[](size_type index) const; // get and set the value at the index position C++ style

    dbuffer(const dbuffer &pT); // copy constructor FONDAMENTALE 3

    dbuffer &operator=(const dbuffer &pT); // assignment operator FONDAMENTALE 4

    ~dbuffer(void); // destructor FONDAMENTALE 2

    friend std::ostream &operator<<(std::ostream &os, const dbuffer &pT); // output operator
};

#endif