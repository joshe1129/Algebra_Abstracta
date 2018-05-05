#include <iostream>
using namespace std;
int main()
{
	float v[3][3]={{1,2,3},{-1,3,2},{5,6,7}};
	float w[3][3];
	float vpw=0;
	float m_w=0;
	float u;
	float suw[3]={0,0,0};
	int n=3;
	/*for(int i = 0; i<3;i++)
	{
	    cout<<"ingrese el vector "<<i<<endl;
	    for(int j=0;j<3;j++)
        {
            cin>>v[i][j];
        }
    }*/
    cout<<"vector w(1)={";
    for(int i=0;i<n;i++)
    {
        w[0][i]=v[0][i];
        cout<<w[0][i]<<",";
    }
    cout<<"}\n";
    for(int j=0;j<n-1;j++)
    {
        for(int i =0;i<3;i++)
        {

            vpw=vpw+v[n-1][i]*w[j][i];
            m_w=m_w+w[j][i]*w[j][i];
        }
        u=vpw/m_w;
        cout<<"u("<<n<<")"<<"("<<j+1<<")="<<u<<endl;
        for(int i =0;i<3;i++)
        {
            suw[i]=suw[i]+u*w[j][i];
        }
        for(int i =0;i<3;i++)
        {
            w[j+1][i]=v[n-1][i]-suw[i];
        }
        cout<<"vector w("<<j+2<<")={";
        for(int i=0;i<3;i++)
        {
            cout<<w[j+1][i]<<",";
        }
        cout<<"}\n";
    }
    return 0;
}
