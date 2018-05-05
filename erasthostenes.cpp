#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main(void)
{
    int n;
    cout<<"ingrese la cantidad de numeros para encontrar los primos hasta ese numero: ";
    cin>>n;
    int primos[n];
    int listaprimos[n];
    int c=0,cont=0;
    bool primo = true;
    for(int i=0;i<=n;i++)
    {
        primos[i]=i+1;
    }
    for(int j=0;j<n;j++)
    {
        for(int i=2;i<=j;i++)
        {
            if(primos[j]%i==0)
                primo=false;
        }
        if(primos[j]==1)
            cout<<"!"<<primos[j]<<"----";
        if(primo==true)
        {
            cout<<primos[j]<<"-----";
            listaprimos[cont]=primos[j];
            cont++;
        }
        else
            cout<<"!"<<primos[j]<<"?---";
        c++;
        if(c==10)
        {
            cout<<endl;
            c=0;
        }
        primo=true;
    }
    cout<<"hay "<<cont-1<<" primos";
    char esc_char = 27; // the decimal code for escape character is 27
cout << esc_char << "[1m" << "Hello Bold!" << esc_char << "[0m" << endl;
}
