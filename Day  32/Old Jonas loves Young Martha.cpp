//no caes passed
#include<bits/stdc++.h>
using namespace std;

   int s=0;
 

void f(int i, int x)
{
    if(i== (x-2))
    {
     s += d[i]+d[i+1];
        return;
    }
   for(int j=i; j<x; j++)
   {
       s += d[i];
   }
    f(i+1,x);
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n+1; i++)
        cin>>a[i];
    
   vector<int>d;
    for(int i=1; i<n; i++)
    {
         d.push_back(abs(a[i]-a[i-1])); 
    }
 
    f(0, d.size());
    cout<<s;
   
    return 0;
}
