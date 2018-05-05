#include<iostream>
#include<string>
using namespace std;

int main () {
    int cont=0;
    int flag=0;
    string str1="Hola,como,estas";
    string str2=",";
    string::iterator it1;
    /*cout<<"Ingrese primer texto: ";
    getline(cin,str1,'\n');
    cout<<"Ingrese segundo texto: ";
    getline(cin,str2,'\n');*/
    for (it1 = str1.begin(); it1 < str1.end(); it1++){
            for(int i=0; i < str2.size(); i++){
                if(it1[i]==str2[i])
                {
                    flag=1;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                cout<<endl;
            else
                cout<<*it1;
    }
    return 0;
}
