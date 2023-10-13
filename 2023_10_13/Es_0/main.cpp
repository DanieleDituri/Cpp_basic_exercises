#include <iostream>
#include <cmath>
#include <cassert>

int main(int argc, char *argv[]){

    int nintervals = 0;

    std::cout << "Inserire numero di intervalli: ";
    std::cin >> nintervals;

    assert(nintervals > 0);
    
    if (nintervals <= 0){
        std::cout << "Inserire un valore valido." << std::endl;
        return 0;
    }

    double delta = M_PI / nintervals;
    double result = 0;
    double x1 = 0, x2 = delta;

    for (int i = 0; i < nintervals; ++i){
        result = result + (std::sin(x1) + std::sin(x2));
        x1 = x2;
        x2 = x2 + delta;
    }
    result = result * 0.5 * delta;

    std::cout << "Il risultato dell'integrale è: " << result << std::endl;

    return 0;
}