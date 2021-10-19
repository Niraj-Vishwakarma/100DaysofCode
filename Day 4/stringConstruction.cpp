// HACKERRANK PROBLEM [ https://www.hackerrank.com/challenges/string-construction/problem ]

/*
 * Complete the 'stringConstruction' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int stringConstruction(string s) {
vector<int> c (26,0);
for(int i=0; i<s.size(); i++)
{
    c[s[i]-'a'] = 1;
}
int cost=0;
for(int i: c)
{
    cost += i;
}
return cost;
}
