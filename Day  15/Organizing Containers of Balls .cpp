//  https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin>>t;
    while(t--)
    {
     //input
     int n ;
     cin>>n;
     vector<vector<int>> c(n, vector<int> (n));
     for(int i=0; i<n; i++)
     {
        for(int j=0; j<n; j++)
        {
            cin>>c[i][j];
        } 
     }
     
     
  vector<int>cb (n,0);
  vector<int>bt (n,0);
 
 //container count
 for(int i=0; i<n; i++)
 {
     for(int j=0; j<n; j++)
     {
         cb[i] += c[i][j];
     }
 }
 
 // ball type coun
  for(int j=0; j<n; j++)
 {
     for(int i=0; i<n; i++)
     {
        bt[j] += c[i][j];
     }
 }

 int count =0 ;
 for(int i=0; i<n; i++)
 {
     for(int j=0 ;j< bt.size(); j++)
     {
         if(cb[i]==bt[j])
         {
             count++;
           bt.erase(bt.begin()+j, bt.begin()+j+1);
         }
     }
 }
  
  if(count == n)
  {
      cout<<"Possible\n";
  }else {
      cout<<"Impossible\n";
  }      
       
        
    }
    return 0;
}
