#include<iostream>
using namespace std;
int modInverse(int a, int mod)
{
    int x;
    for (int i=0; i<mod; i++)
    {
        if(a*i<mod)
        {
            if ((a*i) % mod == 1)
            {
                cout<<a<<"*"<<i<<"="<<(a*i)%mod<<"(mod "<<mod<<")"<<"<---- FOUND INVERSE"<<endl;
                x=i;

            }

            else
                cout<<a<<"*"<<i<<"="<<(a*i)%mod<<"(mod "<<mod<<")\n";

        }
        else{
            if ((a*i) % mod == 1)
            {
               cout<<a<<"*"<<i<<"="<<a*i<<"="<<(a*i)%mod<<"(mod "<<mod<<")"<<"<---- FOUND INVERSE"<<endl;
               x=i;
            }
            else
                cout<<a<<"*"<<i<<"="<<a*i<<"="<<(a*i)%mod<<"(mod "<<mod<<")\n";
          }
    }
    return x;

}
int main()
{
    long a,mod,invmod;
    cout << "Ingrese el primer numero a multiplicar: ";
    cin >> a;
    cout << "Ingrese el modulo: ";
    cin >> mod;
    invmod=modInverse(a, mod);
    cout << invmod<<"is the modular inverse of "<<a<<" mod "<<mod<<" since ";
    cout << invmod<<"*"<<a<<" mod "<<mod <<"="<<(invmod*a)%mod;
    return 0;
}
