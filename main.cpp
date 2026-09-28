#include <iostream>
#include "campo.hpp"

using namespace std;

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