#include<bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   vector<int>ans(n+1, 0);
   vector<int> a(n+1,0);
   
   for(int i=1; i<=n; i++)
   {
       int n;
       cin>>a[i];
   }
   
   for(int i=1;i<a.size(); i++)
   {
       int index;
       index = find(a.begin(), a.end(), i) - a.begin();
       ans[a[i]] = index;    
   }
  
  for(int i=1; i<=n; i++)
  {
     cout<<ans[i]<<"\n"; 
  }
    
    return 0;
}
