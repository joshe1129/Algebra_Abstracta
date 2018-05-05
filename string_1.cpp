#include<iostream>
#include<string>
using namespace std;

int main () {
    string str;
    string::iterator it;
    cout<<"Ingrese un texto: ";
    getline(cin,str,'\n');
    for (it = str.end()-1; it >= str.begin(); it--)
        cout << *it;
    return 0;
}
