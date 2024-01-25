/**
 * @file dbuffer.cpp
 * @brief Implementation file for the dynamic buffer library.
 */
#include <iostream>
#include "dbuffer.h"

namespace dbuffer
{
    void print(const dynamic_buffer &db)
    {
        std::cout << "Size: " << db.size << std::endl;
        if (db.size > 0)
        {
            std::cout << "Buffer: [";
            for (unsigned int i = 0; i < db.size - 1; i++)
            {
                std::cout << db.buffer[i] << ", ";
            }
            std::cout << db.buffer[db.size - 1] << "]" << std::endl;
        }
        else
        {
            std::cout << "Empty buffer" << std::endl;
        }
    }

    void init(dynamic_buffer &db)
    {
        db.size = 0;
        db.buffer = nullptr;
    }

    void set(dynamic_buffer &db, int value)
    {
        for (unsigned int i = 0; i < db.size; i++)
        {
            db.buffer[i] = value;
        }
    }

    void allocate(dynamic_buffer &db, unsigned int size)
    {
        int *tmp = new int[size];

        if (db.buffer != nullptr)
        {
            delete[] db.buffer;
            init(db);
        }

        db.buffer = tmp;
        db.size = size;
        set(db);
    }

    void deallocate(dynamic_buffer &db)
    {
        delete[] db.buffer;
        init(db);
    }

    void copy(const dynamic_buffer &src, dynamic_buffer &dst)
    {
        allocate(dst, src.size);
        for (unsigned int i = 0; i < src.size; i++)
        {
            dst.buffer[i] = src.buffer[i];
        }
    }

}