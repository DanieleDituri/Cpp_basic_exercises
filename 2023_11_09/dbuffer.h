#ifndef DBUFFER_H
#define DBUFFER_H

class dbuffer
{
public:
    typedef unsigned int size_type;

private:
    size_type _size;
    int* _buffer;

public:
    dbuffer(); // default constructor FONDAMENTALE 1

    explicit dbuffer(size_type size); // constructor with size

    dbuffer(size_type size, int value); // constructor with size and value

    void print_buffer() const; // print the buffer

    void fill_buffer(); // fill the buffer

    dbuffer(const dbuffer &pT); // copy constructor FONDAMENTALE 3

    dbuffer& operator=(const dbuffer &pT); // assignment operator FONDAMENTALE 4

    ~dbuffer(void); // destructor FONDAMENTALE 2
};

#endif