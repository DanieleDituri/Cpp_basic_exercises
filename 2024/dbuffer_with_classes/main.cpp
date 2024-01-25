#include <iostream>
#include <cassert>
#include "dbuffer.h"

void f(const dbuffer &d) {}

int main(int argc, char *argv[])
{
    dbuffer db1;

    dbuffer db2(100);

    dbuffer db3(20, 0);

    dbuffer *pdb = new dbuffer();

    dbuffer db4(db3);

    f(db4); // copy constructor is called here
            // when the function returns, the destructor is called

    dbuffer db5 = db4; // copy constructor is called here

    db1 = db2; // assignment operator is called here

    delete pdb; // pdb is a pointer to dbuffer, so we need to use delete to free the memory.
                // we don't need to use delete with db1, db2 and db3 because is automatic.
    pdb = nullptr;

    dbuffer db6(10, 1);

    db6[5] = 100;

    assert(db6[5] == 100);

    db2[2] = db6[5];

    assert(db2[2] == 100);

    db6.print();

    std::cout << db6 << std::endl; // operator<< is called here

    return 0;
}