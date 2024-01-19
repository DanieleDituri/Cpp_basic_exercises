#include <iostream>
#include "dbuffer.h"

namespace dbuffer
{
    void intizialize_buffer(dynamic_buffer &db)
    {
        db.size = 0;
        db.buffer = nullptr;
    }

    void print_buffer(const dynamic_buffer &db)
    {
        std::cout << "[ ";
        for(unsigned int i = 0 ; i < db.size - 1 ; i++)
        {
            std::cout << db.buffer[i] << ", ";
        }
        std::cout << db.buffer[db.size - 1] << " ]" << std::endl;
    }

    void allocate_buffer(dynamic_buffer &db, unsigned int size)
    {
        db.size = size;
        db.buffer = new int[size];
    }

    void deallocate_buffer(dynamic_buffer &db)
    {
        db.size = 0;
        delete[] db.buffer;
    }

    void fill_buffer(dynamic_buffer &db)
    {
        for (unsigned int i = 0 ; i < db.size ; i++)
        {
            std::cout << "Inserisci il valore " << i + 1 << " : ";
            std::cin >> db.buffer[i];
        }
    }

    void copy_buffer(const dynamic_buffer &db1, dynamic_buffer &db2)
    {
        db2.size = db1.size;
        db2.buffer = new int[db1.size];
        for (unsigned int i = 0 ; i < db1.size ; i++)
        {
            db2.buffer[i] = db1.buffer[i];
        }
    }
}