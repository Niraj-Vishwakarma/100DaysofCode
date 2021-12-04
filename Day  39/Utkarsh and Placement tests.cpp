#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        
        char f,s,t,x,y;
        cin>>f>>s>>t>>x>>y;
        
        if(f==x || f==y)
        {
            cout<<f<<"\n";
        }else if (s==x || s==y)
             {
                 cout<<s<<"\n";
             }else {
                  cout<<t<<"\n";
             }
        
        
        
    }
    
    
    
    return 0;
}
