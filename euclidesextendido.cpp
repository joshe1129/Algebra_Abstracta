#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int mcdExtend(int a, int b, int *x, int *y)
{
    if (a == 0)// caso base
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int mcd = mcdExtend(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;    // actualizando 'x' y 'y'
    *y = x1;

    return mcd;

}
int main()
{
    int x,y;
    int num1, num2, result;
    cout << "Ingrese dos numeros para hallar el mcd usando el algoritmo de Euclides: \n";
    cin >> num1 >> num2;
    if(num1 < num2) std::swap(num1, num2);//mcd(a,b)=mcd(b,a)
    result = mcdExtend(num1, num2, &x, &y);
    if(result<0)//num2 es agregado para manejar los resultados negativos
    {
        result=(x%num2 + num2) % num2;
    }
    if (num2!=0)
        cout << "\nEl MCDExtendido(" << num1 << "," << num2 <<")= " << result <<" x = "<<x<<" y = "<<y<<endl;
    else
        cout << "\nIngreso invalodo!!!\n";
    return 0;
}
