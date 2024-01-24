#include <iostream>
#include "nsqrt.h"

double nsqrt(double x, double epsilon)
{
    double s0 = x / 2;
    double sk = (s0 * s0 + x)/(2 * s0);

    while(sk * sk - x > epsilon)
    {
        sk = (sk * sk + x)/(2 * sk);
    }
    
    return sk;
}