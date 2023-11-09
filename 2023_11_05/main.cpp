#include <iostream>
#include "dbuffer.h"

using namespace dbuffer;

int main()
{
    dynamic_buffer db1, db2;

    std::cout << "Test Inzializzazione" << std::endl;
    intizialize_buffer(db1);
    std::cout << std::endl;

    std::cout << "Test Allocation size 2" << std::endl;
    allocate_buffer(db1, 2);

    std::cout << "Test stampa size 2" << std::endl;
    print_buffer(db1);
    std::cout << std::endl;

    std::cout << "Test Allocation defualt" << std::endl;
    allocate_buffer(db2);

    std::cout << "Test stampa defualt" << std::endl;
    print_buffer(db2);
    std::cout << std::endl;

    std::cout << "Test deallocation default" << std::endl;
    deallocate_buffer(db2);
    std::cout << "print_buffer(db2) se eseguito stamperà valori casuali perchè deallocato" << std::endl;
    std::cout << std::endl;

    std::cout << "Test fill size 2" << std::endl;
    fill_buffer(db1);
    std::cout << "db appena inserito:" << std::endl;
    print_buffer(db1);
    std::cout << std::endl;

    std::cout << "Test copy" << std::endl;
    copy_buffer(db1, db2);
    std::cout << "db da copiare: ";
    print_buffer(db1);
    std::cout << "db copiato: ";
    print_buffer(db2);
    std::cout << std::endl;

    std::cout << "Modifico il db da copiare" << std::endl;
    fill_buffer(db1);
    std::cout << "nuovo db da copiare: ";
    print_buffer(db1);
    std::cout << "db copiato non aggionato: ";
    print_buffer(db2);

    return 0;
}