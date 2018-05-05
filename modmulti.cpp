#include<iostream>
using namespace std;

int main()
{
    long num1, num2 , num3;
    cout << "Ingrese el primer numero a multiplicar: ";
    cin >> num1;
    cout << "Ingrese el segundo numero a multiplicar: ";
    cin >> num2;
    cout << "Ingrese el modulo: ";
    cin >> num3;
    cout<<"(A * B) mod C = (A mod C * B mod C) mod C \n";
    cout << "("<<num1<<"mod"<<num3<<"*"<<num2<<"mod"<<num3<<")"<<"mod"<<num3<<endl;
    cout << "("<<num1%num3<<"*"<<num2%num3<<")"<<"mod"<<num3<<endl;
    cout <<  (num1%num3)*(num2%num3) << "mod"<< num3<<endl;
    cout << (num1%num3)*(num2%num3)%num3;
    return 0;
}
