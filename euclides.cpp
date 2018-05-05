#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int mcd(int u, int v)
{
    return (v != 0) ? mcd(v, (u-((u/v)*v))) : u;
}
int main(void)
{
    int num1, num2, result;
    cout << "Ingrese dos numeros para hallar el mcd usando el algoritmo de Euclides: \n";
    cin >> num1 >> num2;
    result = mcd(num1, num2);
    if(result<0)
    {
        result=num2+result;
    }
    if (mcd)
        cout << "\nEl MCD de " << num1 << " y " << num2 << " es: " << result
                << endl;
    else
        cout << "\nIngreso invalodo!!!\n";
    return 0;
}
