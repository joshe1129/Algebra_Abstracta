#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
bool _e(int n)
{
     int i,sq,count=0;
     if(n==1)
       return false;
	 if(n==2)
       return true;
     if(n%2==0)
       return false;
     sq=sqrt(n);
     for(i=2;i<=sq;i++)
      if(n%i==0) return false;
      return true;
}
bool is_prime(int n)
{
     int i,sq,count=0;
     if(n==1)
       return false;
	 if(n==2)
       return true;
     if(n%2==0)
       return false;
     sq=sqrt(n);
     for(i=2;i<=sq;i++)
      if(n%i==0) return false;
      return true;
}
int gcd(int a, int h) //maximo comun divisor
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}
int modInverse(int a, int m)
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
int modExp(int b, int e, int n)
{
    int binario;
    int x = 1;
    while (e != 0)
    {
        binario = e % 2;
        e= e/2;
        if (binario == 1)
            x = (x * b) % n;
        b= (b * b) % n;
    }
    return x;
}


int main()
{
    int p,q,n,phi,e=1,d;

    do{
        p = rand() % 100 + 1;

    }while(!is_prime(p));
    do{
        q = rand() % 100 + 1;

    }while(!is_prime(q));
    n=p*q;
    phi=(p-1)*(q-1);
    do{
        e = rand() % phi + 1;

    }while(gcd(e,phi)!=1);
    /*while (e < phi)
    {
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }*/
    d=modInverse(e,phi);
    cout<<"\nclave Publica = "<< e<<", "<<n;
    cout<<"\nclave Privada = "<< d<<", "<<n;
    double msg = 2;
    cout<<"\nMesaje = "<<msg;
    double c = modExp(msg,e,n);
    cout<<"\nMensaje encriptado = "<<c;
    double m = modExp(c,d,n);
    cout<<"\nMensaje desencriptado = "<<m;
    return 0;
}
