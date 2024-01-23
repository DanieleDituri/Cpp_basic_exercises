#include <iostream>


struct pippo
{
    char c1;
    int i;
    char c2;
};

int main(int argc, char* argv[])
{
    std::cout << sizeof(pippo) << std::endl;

    return 0;
}