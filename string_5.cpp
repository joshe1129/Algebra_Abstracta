#include<iostream>
#include<string>
using namespace std;

int main () {
    int cont=0;
    int flag=0;
    string str1="abcde";
    //string str2="aba";
   // string str1;
    string::iterator it1;
    string::iterator it2;
    //cout<<"Ingrese texto: ";
   // getline(cin,str1,'\n');
    for (it1 = str1.begin(); it1 < str1.end(); it1++){
            for(it2 = str1.end()-1; it2 > str1.begin(); it2--){
                    cout<<*it1<<"=="<<*it2;
                if(*it1==*it2)
                {
                    flag=1;
                    break;
                }
                else{
                    flag=0;
                    cout<<"NO";
                    return 0;
                }
            }

    }
    cout<<"SI";
    return 0;
}
