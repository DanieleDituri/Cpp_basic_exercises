#include <iostream>
#include <cassert>
#include "dbuffer.h"

int main()
{
    dbuffer db1(2);
    db1.fill_buffer();
    db1.print_buffer();

    dbuffer db2;
    // db2.print_buffer(); this will cause an error because the buffer is empty

    dbuffer db3(10, 0);
    db3.print_buffer();

    dbuffer db4(db1);
    db4.print_buffer();

    dbuffer *pdb = new dbuffer();

    delete pdb; // destructor is explicitly called for the pointer
                // because it was created with the new keyword (dynamic allocation)

    db3[5] = 100;
    assert(db3[5] == 100);

    db3[3] = db3[5];
    assert(db3[3] == 100);

    std::cout << db3;

    return 0;
}