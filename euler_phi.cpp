#include<iostream>
#include <math.h>
 using namespace::std;
int Tamano_Arreglo;
void Criba( int A[], int Tamano);

int main()
{
    cout<<"ingrese numero: ";
    cin>>Tamano_Arreglo;
    int Arreglo[Tamano_Arreglo + 1] = { 0, 0};
    Criba( Arreglo, Tamano_Arreglo );
    int factores[4];
    int cont=0;
    int indice=0;
    int flag;
    int fun=1;
    cout<<"Ç("<<Tamano_Arreglo<<")=";
    for(int i=2;i<=Tamano_Arreglo;i++)
    {
        while(Tamano_Arreglo%i==0)
        {
            cont++;
            Tamano_Arreglo=Tamano_Arreglo/i;
            flag=1;
        }
        if(flag==1)
        {
            factores[indice]=cont;
            cout<<"("<<i<<"^"<<cont<<"-"<<i<<"^"<<cont-1<<")";
            indice++;
            fun=fun*(pow(i,cont)-pow(i,cont-1));
         }
          if(Tamano_Arreglo%i!=0)
          {
              cont=0;
              flag=0;
          }

     }
     cout<<"="<<fun;

     return 0;
 }
 void Criba( int A[], int Tamano )
 {
    int contador = 0;
    for ( int i = 1; i <= Tamano_Arreglo; i++ )
        A[i] = 1; //EN PRINCIPIO TODOS LOS NUMEROS SE CONSIDERAN PRIMOS
    for ( int j = 2; j <= Tamano_Arreglo; j++ )
        for ( int k = 2; k <= (Tamano_Arreglo)/j; k++ )
            A[k*j] = 0;//LUEGO CAMBIA CADA MULTIPLO COMO UN NO PRIMO

    for ( int m = 1; m <= Tamano; m++ )
    {
        if ( 1 == A[m] )
            contador++;
    }
    cout <<"\n\nEstos son los " << contador << " numeros primos que hay ";
    cout <<"entre 1 y " << Tamano << endl;
    for ( int n = 1; n <= Tamano; n++ )
    {
        if ( 1 == A[n] )
        {
            cout <<" " << n << "\t";
        }
    }
    cout << endl <<endl;
 }

