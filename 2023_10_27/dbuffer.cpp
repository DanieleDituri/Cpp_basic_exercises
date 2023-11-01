#include "dbuffer.h"
#include <iostream>
#include <cassert>

namespace dbuffer {

  void print_dbuffer(const dynamic_buffer &db) {
    std::cout << db.size << " [ ";
    for(unsigned int i = 0; i < db.size; ++i)
      std::cout << db.buffer[i] << " ";
    std::cout << "]" << std::endl;
  }

  void initialize_dbuffer(dynamic_buffer &db) {
    db.size = 0;
    db.buffer = nullptr;
  }

  void allocate_dbuffer(dynamic_buffer &db, unsigned int size) {

    int *tmp = new int[size];

    deallocate_dbuffer(db);

    db.size = size;
    db.buffer = tmp;
  }

  void deallocate_dbuffer(dynamic_buffer &db) {
    delete[] db.buffer;
    initialize_dbuffer(db);
  }

  void fill_dbuffer(dynamic_buffer &db, int value) {
    for(unsigned int i=0; i<db.size; ++i)
      db.buffer[i] = value;
  }

  void fill_dbuffer(dynamic_buffer &db, const int*values, int nvalues) {
    assert(values!=nullptr);
    assert(nvalues == db.size);

    for(unsigned int i=0; i<db.size; ++i)
      db.buffer[i] = values[i];
  }
  
  void copy_dbuffer(const dynamic_buffer &src, dynamic_buffer &dst) {     
    allocate_dbuffer(dst,src.size);
    fill_dbuffer(dst,src.buffer,src.size);
  }


}