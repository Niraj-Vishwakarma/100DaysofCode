// first

#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    stack<char> s;
    char c;
      cin>>c;
    s.push(c);

   while(--n)
   {
       char c;
      cin>>c;
       if(s.top()!=c)
       s.push(c);
      
       
   }
    
    cout<<s.size();
    return 0;
}

//second

#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    string a;
    cin>>n>>a;
    stack<char> s;
    s.push(a[0]);
    for(int i=1; i<n; i++)
    {
          if(s.top() != a[i])
          { s.push(a[i]);
          }     
    }
    cout<<s.size();
    return 0;
}
