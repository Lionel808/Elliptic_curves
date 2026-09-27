#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

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

struct Campo
{
private:
    int p;

public:
    Campo(int modulo)
    {
        if (!isPrime(modulo))
            throw invalid_argument("O modulo deve ser primo");

        p = modulo;
    }

    long sumMod(int a, int b)
    {
    return (a + b) % p;
    }

    long multMod(int a, int b)
    {
        return (a * b) % p;
    }
    
    long subMod(int a, int b)
    {
        return (a - b + p) % p;
    }

    long invMult(int b)
    {
        b = (b % p + p) % p;

        for (int x = 1; x < p; x++)
        {
            if ((b * x) % p == 1)
                return x;
        }
        return -1;
    }

    long divMod(int a, int b)
    {
        long invb = invMult(b);

        if (invb == -1)
        {
            return -1;
        }        

        return multMod(a, invb);
    }
};

int main()
{
    int moduloP;

        do
        {   
            cout << "sabendo que p deve ser primo," << endl;
            cout << "insira p: ";
            cin >> moduloP;
        } while (!isPrime(moduloP));
    
    Campo campoF(moduloP);

    int a = 0;
    int b = 0;  
    do 
    {
        cout << "sabendo que a deve ser >= 0 e < p," << endl;
        cout << "insira a: ";
        cin >> a;
    } while (a < 0 || a >= moduloP);

    do
    {
        cout << "sabendo que b deve ser >= 0 e < p," << endl;
        cout << "insira b: ";
        cin >> b;
    } while (b < 0 || b >= moduloP);

    cout << "soma: " << campoF.sumMod(a, b) << endl;
    cout << "multiplicação: " << campoF.multMod(a, b) << endl;
    cout << "subtração: " << campoF.subMod(a, b) << endl;
    cout << "inv multiplicativo de a: " << campoF.invMult(a) << endl;
    cout << "inv multiplicativo de b: " << campoF.invMult(b) << endl;
    cout << "divisão: " << campoF.divMod(a, b) << endl;
    

    /*
    long sum = sumMod(a, b); 
    long mult = multMod(a, b);
    long inv = invMod(a);
    long div = divMod(a, b);
    */
    return 0;
}