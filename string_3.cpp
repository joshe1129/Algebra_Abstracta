#include<iostream>
#include<string>
using namespace std;

int main () {
    int n=0;
    cin>>n;
    while(n%2==0)
    {
        cout<<"el numero debe ser impar, vulva a ingresar \n";
        cin>>n;
    }
    for(int y=0; y<n; ++y)
    {
        for(int x=0; x<n; ++x)
        {
            cout << (abs(x-n/2)+abs(y-n/2)<=n/2 ? "*" : " ");
        }
        cout << endl;
    }

}
