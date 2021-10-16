//Hackerrank Problem [https://www.hackerrank.com/challenges/reduced-string/copy-from/238634400]

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    
for(int i=1; i<s.length(); i++)
{
    if(s[i]==s[i-1])
    { 
        s.erase(i-1, 2);
        i=0;
    }
}

if(s.length()==0) 
return "Empty String";

return s;

}

int main()
{
    string s;
    getline(cin, s);

    string result = superReducedString(s);

    cout << result << "\n";

    return 0;
}
