#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    //for (int i = 0 ; i < argc ; i++)
    //{
        std::cout << argv[1] << std::endl;
    //}

    std::stringstream ss(argv[1]);

    bool v;

    ss >> v;

    std::cout << v << std::endl;

    return 0;
}