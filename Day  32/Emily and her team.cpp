//did not passed cases
#include<bits/stdc++.h>
using namespace std;


int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,b;
        cin>>n>>b;
        int a[2][n];
        
        for(int i=0; i<n; i++)
            cin>>a[0][i];
        for(int i=0; i<n; i++)
            cin>>a[1][i];
        
        int g=101,m=101,d=101,f=101;
        for(int i=0;i<n; i++)
        {
             switch(a[1][i])
             {
                 case 0:
                        g= min(g, a[0][i]);
                     break;
                      case 1:
                     m= min(m, a[0][i]);
                     break;
                      case 2:
                     d= min(d, a[0][i]);
                     break;
                      case 3:
                     f= min(f, a[0][i]);
                     break;
             }
        }
        int r = b - g+f+m+d;
        if(r>=0)
        { cout<<"yes\n";
        }else{cout<<"no\n";}
        
        
    }
    
    return 0;
}
