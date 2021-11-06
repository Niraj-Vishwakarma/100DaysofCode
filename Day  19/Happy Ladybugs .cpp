#include <bits/stdc++.h>

using namespace std;

int main()
{
    int g;
    cin>>g;
    while(g--)
    {
       string b;
       int l;
       bool empty = false;
       cin>>l;
       cin>>b;
       vector<int> c(26,0);
       
       for(int i=0; i<l; i++)
       {
           if(b[i] == '_')
           {
              empty = true;
           } else {
                c[b[i]-'A']++;
           }
       }
       
        int flag =0;
           for(int i : c)
           {
               if(i==1)
               {
                   flag=1;
                   break;
               }
           }
           
            if(flag==0 && empty)
             { cout<<"YES\n";}
           else
            { 
                int flag2=0;
                if(flag ==1)
                {
                    cout<<"NO\n";
                } else {
                 
                        for(int i=1; i<l-1; i++)
                      {
                         if( b[i] != b[i+1]  &&  b[i]!=b[i-1])
                        {
                          
                           flag2=1;
                              
                        } 
                    } 
                          if(flag2==0)
                          {cout<<"YES\n";}
                          else {
                          cout<<"NO\n";
                          }
                
                }
                
            }  
    }   
    return 0;
}
