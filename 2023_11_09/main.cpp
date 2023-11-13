#include <iostream>
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

    return 0;
}