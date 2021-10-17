// Hackerrank problem [ https://www.hackerrank.com/challenges/pangrams/problem ]

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
     vector<int> c(26,0);
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>=97 && s[i]<=122)
        c[s[i]-97] = 1;
        
        if(s[i]>=65 && s[i]<=90)
        c[s[i]-65] = 1;    
    }  
 
    for(int i :c)
    {
       if(i==0)
       return "not pangram";
    }
    
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
