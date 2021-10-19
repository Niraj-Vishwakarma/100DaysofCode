//HACKERRANK PROBLEM [ https://www.hackerrank.com/challenges/anagram/problem ]

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
// approach -1 
int anagram(string s) {
int l = s.length(); 
if(s.length()%2==0)
{
    string s1 = s.substr(0, l/2 );
    string s2 = s.substr(l/2 , l/2);
    for(int i=0; i<s1.length(); i++)
    {
        for(int j=0; j<s2.length(); j++)
        {
            if(s1[i]==s2[j])
            {
                s2.erase(j,1);
                break;
            }
        }
    }
    return s2.length();
}
return -1;
}

// approach -2
int anagram(string s) {
int l = s.length(); 
if(s.length()%2==0)
{
    string s1 = s.substr(0, l/2 );
    string s2 = s.substr(l/2 , l/2);
    vector<int> c (26,0);
    for(int i=0; i<s1.length(); i++)
    {
      c[s1[i]-'a']++;  
    }
    for(int i=0; i<s2.length(); i++)
    {
      c[s2[i]-'a']--;  
    }
    int res =0;
   for(int i=0; i<26; i++)
   {
       res += abs(c[i]);
   }
    return res/2;
}
return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
