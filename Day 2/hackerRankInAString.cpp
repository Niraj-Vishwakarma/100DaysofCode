// hackerrank problem [ https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem ]

#include <bits/stdc++.h>

using namespace std;

string hackerrankInString(string s)
{
     string str = "hackerrank";
     int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (j < str.length() && s.at(i) == str.at(j)) {
                    j++;
            }
        }
        return (j == str.length() ? "YES" : "NO");
}


int main()
{
  int t; 
  cin>>t;
  while(t!=0)
  {
      string s;
      cin>>s;
      cout<< hackerrankInString(s)<<endl;
       t--;
  }  
}


