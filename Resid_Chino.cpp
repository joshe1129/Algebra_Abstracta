#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int mcd(int u, int v)
{
    return (v != 0) ? mcd(v, (u-((u/v)*v))) : u;
}
int inv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
       return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;
    return x1;
}
int findMinX(int a[], int m[], int k)
{
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= m[i];
    cout<<"el producto de los modulos 'm' es: "<<prod<<endl;
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int pp = prod / m[i];
        cout<<"M"<<i+1<<" = "<<prod<<"/"<<m[i]<<" = "<<pp<<endl;
        int g = mcd(pp, m[i]);
        if (g != 1)
        {
            cout <<pp<<" y "<<m[i]<<" no son co-primos"<<endl;
            return 0;
        }
        result += a[i] * inv(pp, m[i]) * pp;
    }
    return result % prod;
}
int main(void)
{
    int n;
    cout<<"Ingrese la cantidad de ecuaciones: \n";
    cin>>n;
    int a[n];
    int m[n];
    int pro=1;
    for(int i = 0; i<n; i++)
    {
        cout<<"ingrese a_"<<i+1<<":";
        cin>>a[i];
        cout<<"ingrese el modulo m_"<<i+1<<":";
        cin>>m[i];
        pro=pro*m[i];
    }
    cout<<pro;
    cout<<"las ecuaciones son:"<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<"x="<<a[i]<<"(mod "<<m[i]<<")"<<endl;
    }
    cout << "x is " << findMinX(a, m, n)<<"(mod "<<pro<<")"<<endl;
    return 0;
}
