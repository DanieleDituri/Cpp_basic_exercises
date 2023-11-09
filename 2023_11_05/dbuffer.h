#ifndef DBUFFER_H
#define DBUFFER_H

namespace dbuffer
{
    struct dynamic_buffer
    {
        unsigned int size;
        int *buffer;
    };

    void intizialize_buffer(dynamic_buffer &db);

    void print_buffer(const dynamic_buffer &db);

    void allocate_buffer(dynamic_buffer &db, unsigned int size = 10);

    void deallocate_buffer(dynamic_buffer &db);

    void fill_buffer(dynamic_buffer &db);

    void copy_buffer(const dynamic_buffer &db1, dynamic_buffer &db2);
}

#endif