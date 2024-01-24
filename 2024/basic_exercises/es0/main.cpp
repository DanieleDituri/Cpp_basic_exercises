#include <iostream>
#include<cmath>

int main(int argc, char* argv[])
{
    std::cout << "Quanti sotto intervalli vuoi usare?" << std::endl;
    int n;
    std::cin >> n;

    double delta = M_PI / n;

    double integral = 0.0;

    for (int i = 1 ; i < n ; ++i)
    {
        integral += std::sin(i - 1) + std::sin(i);
    }
    integral = integral * delta / 2;

    std::cout << "L'integrale vale: " << integral << std::endl;

    return 0;
}