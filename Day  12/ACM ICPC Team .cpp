https://www.hackerrank.com/challenges/acm-icpc-team/problem

//O[N^3]
#include <bits/stdc++.h>

using namespace std;

vector <string> v;
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int val = 0;
            for (int k = 0; k < m; k++) {
                if (v[i][k] == '1' || v[j][k] == '1') {
                    val++;
                }
            }
            if (ans < val) {
                ans = val;
                cnt = 1;
            } else if (ans == val) {
                cnt++;
            }
        }
    }
    cout << ans << endl << cnt << endl;
    return 0;
}

//O[n^2] using bitset
#include <bits/stdc++.h>

using namespace std;

vector <string> v;
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    int tmax=0;
    int team=0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
    bitset<500>s1(v[i]);
    
    bitset<500>s2(v[j]);
    
    bitset<500>s3;
    
    
    s3 = s1 | s2 ;
     
    if(s3.count() > tmax )
    {
        tmax = s3.count();
        team=0;
    }
    
    if(s3.count()==tmax)
    {
        team++;
    }
        }
      
    }
    cout << tmax << endl << team << endl;
    return 0;
}




