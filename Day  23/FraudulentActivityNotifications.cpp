//passed 3 test cases
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //input
    int n, d, noti = 0;
    cin>>n>>d;
    vector<int>a(n);
    for(int i=0; i<n; i++)
    cin>>a[i];
    //evaluate
    vector<int>td(d);
     float median;
        for(int j=0; j<d; j++)
        {
            td[j] = a[j]; 
        }
     sort(td.begin(), td.end());   
     if(d%2==1)
     {
         median = td[d/2];
     }else {
         median = td[d/2] + td[(d/2)-1];
         median /= 2;
     } 
    for(int i=d; i<n; i++)
    {
       if(median*2 <= (float)a[i])
       {
           noti++;
       }
       
       //find a[d-3] in t
       
       for(int j=0; j<d; j++)
       {
       
           if(td[j] == a[d-3])
           {
               for(int k=j+1; k<d; k++)
               {td[k-1] = td[k];}
               break;
           }
       } 
      
       td[d-1] = a[i];
      
       
       for(int j=d-1; j>0; j--)
       {
           int temp;
           if(a[i] < td[j-1])
           {
              td[j] = td[j-1];
              td[j-1] = a[i];
                 
           }else {
           break;
           }
       }
       
       //find median
       if(d%2==1)
     {
         median = td[d/2];
     }else {
         median = td[d/2] + td[(d/2)-1];
         median /= 2;
     } 
     
             
    }
    
    
    cout<<noti;
    
    return 0;
}
//Approach second that passed all test cases
#include <bits/stdc++.h>
using namespace std;

int alert=0;
int check(vector<int> f, int d)
{
    vector<int>fc (f);
  for(int i=1; i<201; i++)
    fc[i] += fc[i-1];
    

    int a=0;
    int b=0;
    
    if((d&1) == 1)
    {
        int first = d/2 +1;
        for(int i=0; i<201;i++)
        {
            if(first<=fc[i])
            {
                a= 2*i;
                break;
            }
        }
    } else {
    int first = d/2;
    int sec = first+1;
    int i=0;
    
        for( ; i<201; i++)
        {
            if(first<=fc[i])
             {a = i;
             break;
             }
        }
         for( ; i<201; i++)
        {
            if(sec<=fc[i])
             {b = i;
             break;
             }
        }
    }
    
     
    return a+b;   
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //input
    int n, d;
    cin>>n>>d;
    vector<int>a(n);
    for(int i=0; i<n; i++)
    cin>>a[i];
    //evaluate
    vector<int>f(201,0);
    for(int i=0; i<d; i++)
    {
        f[a[i]]++; 
    }
    for(int i=d; i<n; i++)
    {
        int mediantwice = check(f, d);
        
        if(a[i]>=mediantwice)
        {
            alert++;
        }
        f[a[i]]++;
        f[a[i-d]]--;
    }
    cout<<alert;
    return 0;
}

