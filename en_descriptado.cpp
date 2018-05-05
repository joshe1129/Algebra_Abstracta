#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
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
int main()
{
    char name[30],target[30],ch,mod;      //Declare Variables
    int num[100],i,option,kpub,kpri,tam=0;
    cout<<"Ingresa una opcion: \n";
    cout<<" 1.Para encriptar un archivo \n";
    cout<<" 2. Para desencriptar un archivo \n";
    cout<<" Opcion : ";
    cin>>option;
    if(option==1)
    {
        cout<<"Ingrese el nombre del archivo que desea encriptar: ";
        cin>>name;
        cout<<"Ingrese una clave entre 1 y 26 \n";
        cin>>kpri;
        ifstream fin(name,ios::binary);      //Open The Input File In A Binary Mode
        if(!fin)
        {                  //Show Error Occur If File Does Not Exist
            cout<<"Error en abrir el archivo: ";                 //Or Any Error Occurs
            return 1;
        }
        cout<<" Ingrese el nombre del archivo para encriptar: ";
        cin>>target;
        ofstream fout(target,ios::binary);     //Open The OutPut File In A Binary Mode
        if(!fout)
        {
            cout<<" Error en abrir el archivo: ";        //Show Error If Any Error Occrs In Opening Of A File
            return 1;
        }
        while(fin.get(ch))
        {
            mod= ch+(kpri%26);
            fout<<mod;
        }
        fin.close();                                          //Close The Input File
        fout.close();                                         //Close The Output File
        cout<<" Your File Is Encrypted Now........... ";
    }
    if(option==2)
    {
        char name[30],target[30],ch,mod;                             //Declare Variables
        int num[100],i,flag;
        cout<<"Ingresa el nombre del archivo a desencriptar : ";
        cin>>name;
        kpub=modInverse(kpri,256);
        ifstream fin(name,ios::binary);
        if(!fin)                                                     //Open The Encryped File In A Binary Mode
        {
            cout<<"Error en abrir el archivo: ";
            return 1;                                                    //Show Error If File Does Not Exist
        }                                                            //Or Any Occurs In Opening Of A File
        cout<<" Ingrese un nombre para el archivo desencriptado: ";
        cin>>target;
        ofstream fout;
        fout.open(target,ios::binary);                              //Opens The Output File In An Binary Mode
        if(!fout)
        {                                                          //Show Error If Any Error Occurs In Opening Of A File
            cout<<"Error en abrir el archivo: ";
            return 1;
        }
        while(fin.get(ch))
        {                                                           //Opens The Encryped File
            mod=ch-(kpri%26);                                             //If Match Then Put Appropriate Letter
            fout<<mod;                                               //In A OutPut File
        }
        fin.close();                                        //Close The Encrypted File
        fout.close();                                       //Close Your Original Decrypted File
        cout<<"El archivo esta siendo desencriptado...... ";
        getch();
        return 0;
        }
    return 0;
}
