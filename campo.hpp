#ifndef CAMPO_HPP
#define CAMPO_HPP

bool isPrime(int n);

struct Campo
{
private:
    int p;

public:
    Campo(int modulo);
    long sumMod(int a, int b);
    long multMod(int a, int b);
    long subMod(int a, int b);
    long invMult(int b);
    long divMod(int a, int b);
};

#endif