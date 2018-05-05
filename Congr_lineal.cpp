#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int gcd(int m, int n)
{
    int r;
    if((m == 0) || (n == 0))
        return 0;
    else if((m < 0) || (n < 0))
        return -1;
    do
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    while(true);
    return n;
}
int extendedGCD(int value1, int value2)
{
    int x = 0, y = 1;
    int prevx = 1, prevy = 0;
    while (value2 != 0)
    {
        int holdValue = value2;
        int quotient = value1 / value2;
        value2 = value1 % value2;
        value1 = holdValue;
        holdValue = x;
        x = prevx - quotient * x;
        prevx = holdValue;
        holdValue = y;
        y = prevy - quotient * y;
        prevy = holdValue;
    }
    cout <<"Los coeficientes de Bezout son " << "X: " << prevx << " Y:" << prevy << endl;

    return prevx;
}
int main(void)
{
    int a,b,mod;
    cout<<"ingrese los valores para la congruencia lineal de forma ax=b(mod m)\n";
    cout<<"ingrese a: ";
    cin>>a;
    cout<<"ingrese b: ";
    cin>>b;
    cout<<"ingrese el modulo: ";
    cin>>mod;
    cout<<"la ecuacion es de la forma: "<<a<<"x="<<b<<"(mod "<<mod<<")\n";
    int mcd = gcd(a,mod);
    int soluciones[mcd];
    int modprincipal=mod;
    printf("El maximo comun divisor de %d y %d es: %d\n", a, mod, mcd);
    if(b%mcd==0)
    {
        a=a/mcd;
        b=b/mcd;
        mod=mod/mcd;
        cout<<"la ecuacion es de la forma: "<<a<<"x="<<b<<"(mod "<<mod<<")\n";
        cout<<"esta congruencia tendra "<<mcd<<"soluciones x0,x0+"<<mod<<"x0+"<<mod+mod<<"..."<<endl;
    }
    int inv=extendedGCD(a,mod);
    cout<<"El inverso de "<<a<<"(mod "<<mod<<") es: "<<inv<<endl;
    int x0=(b*inv);

    cout<<"la solucion general es "<<x0<<"="<<modprincipal+x0<<"(mod "<<mod<<")"<<"y las soluciones de la congruencia original son : \n";
    x0=modprincipal+x0;
    for(int i=0;i<=mcd;i++)
            soluciones[i]=mod*i+x0;
     for(int i=0;i<mcd;i++)
            cout<<soluciones[i]<<" \n";
    getchar();
    return 0;
}
