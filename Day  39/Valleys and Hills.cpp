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
        int n,m;
        string ans ;
        cin>>n>>m;
        if(n==m)  //same number of hills and valleys
        {
            ans += "01";
            while(m--)
            {
               ans += "01"; 
            }
        } else if( n>m)
               {
                   int diff= n-m;
                   int same = n-diff;
                   if(diff == 1)
                   {
                       ans += "01";
                       while(same--)
                       {
                           ans+="01";
                       }
                       ans += "0";
                       
                   } else {        // m-n > 1
                       ans += "01";
                          while(same--)
                       {
                           ans+="01";
                       }
                       ans += "0";
                       diff--;
                       while(diff--)
                       {
                           ans += "010";
                       }
                        
                   }
                   
                   
                   
                   
                   
                   
                   
                   
               }else  //m>n
               {
                   
                    int diff2 = m-n;
                    int same2 = m-diff2;
                    if(diff2==1)
                    {
                        ans += "10";
                        while(same2--)
                        {
                            ans += "10";
                        }
                        ans += "1";
                    } else 
                    {
                        ans += "10";
                        while(same2--)
                        {
                            ans += "10";
                        }
                        ans += "1";
                        diff2--;
                        while(diff2--)
                        {
                            ans += "101";
                        }
                        
                        
                    }
                   
               }
        cout<<ans.size()<<"\n";

        cout<<ans<<"\n";
    }
    
    
    return 0;
}
