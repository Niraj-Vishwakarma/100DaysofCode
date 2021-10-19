// HACKERRANK PROBLEM [ https://www.hackerrank.com/challenges/two-strings/problem ]

string twoStrings(string s1, string s2) {
string letter = "abcdefghijklmnopqrstuvwxyz";
for(int i=0; i<26; i++)
{
    if(s1.find(letter[i]) != -1 && s2.find(letter[i]) != -1 )
    {
        return "YES";
    }
}
return "NO";
}
