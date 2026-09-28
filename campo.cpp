#include "campo.hpp"
#include <stdexcept>

bool isPrime(int n)
{
    if (n < 2)
        return false;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

Campo::Campo(int modulo)
{
    if (!isPrime(modulo))
        throw std::invalid_argument("O modulo deve ser primo");
    
    p = modulo;
}

long Campo::sumMod(int a, int b)
{
return (a + b) % p;
}

long Campo::multMod(int a, int b)
{
    return (a * b) % p;
}

long Campo::subMod(int a, int b)
{
    return (a - b + p) % p;
}

long Campo::invMult(int b)
{
    b = (b % p + p) % p;

    for (int x = 1; x < p; x++)
    {
        if ((b * x) % p == 1)
            return x;
    }
    return -1;
}

long Campo::divMod(int a, int b)
{
    long invb = invMult(b);

    if (invb == -1)
    {
        return -1;
    }        

    return multMod(a, invb);
}