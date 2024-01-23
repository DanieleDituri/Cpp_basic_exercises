#include <iostream>

int main(int argc, char* argv[])
{
    int v = 2;

    int &vr = v;

    std::cout << &v << std::endl;
    std::cout << &vr << std::endl;

    const int *pv = nullptr;

    pv = &v;

    *(const_cast<int*>(pv)) = 90;

    return 0;
}