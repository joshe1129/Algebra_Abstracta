#include<iostream>
#include <stdio.h>      /* printf */
#include <math.h>       /* floor */
using namespace std;
string toBinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
};


int main()
{
    int a,b,c;
    cout<<"ingrese un numero:";
    cin>>a;
    cout<<"ingrese un exponencial:";
    cin>>b;
    cout<<"ingrese modulo";
    cin>>c;
    int cont,exp;
    string bin;
    bin=toBinary(b);
    cout<<"el numero en binario es:"<<bin<<endl;
    cont=0;
    for(int i=0;i<=bin.length();i++)
    {
        if(bin[i]=='1')
        {
            cont++;
        }
    }
    cout<<cont<<endl;
    int tam=cont;
    int exparr[cont];
    cont=0;
    exp=bin.length()-1;
    for(int i=0;i<=bin.length();i++)
    {
        if(bin[i]=='1')
        {
            exparr[cont]=pow(2,exp);
            exp--;
            cont++;
        }
        else
            exp--;
    }
    for(int i=0;i<tam;i++)
        cout<<exparr[i]<<endl;



}


