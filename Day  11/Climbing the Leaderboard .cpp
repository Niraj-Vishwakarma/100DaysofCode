
//Basic approach - 4 TLE
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> p) {
        vector<int>ans;
        int r[ranked.size()];
        int ra = 1;
        r[0] = ra;
        for(int i=1; i<ranked.size(); i++)
        {
            if(ranked[i]==ranked[i-1])
            {
                r[i]=r[i-1];
            }else {
                ra++;
                r[i] = ra;
            } 
        }
        
        for(int i=0; i<p.size(); i++)
        {
            for(int j=0; j<ranked.size();j++)
            {
                if(p[i]>=ranked[j])
                {
                  ans.push_back(r[j]); 
                  break; 
                } else if(j==ranked.size()-1)
                       {
                           ans.push_back(r[j]+1);
                       }
                
            }
        }

return ans;
}

// Second approach  - 1 test case not passed
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> p) {
        vector<int>ans;
        int r[ranked.size()];
        int ra = 1;
        r[0] = ra;
        for(int i=1; i<ranked.size(); i++)
        {
            if(ranked[i]==ranked[i-1])
            {
                r[i]=r[i-1];
            }else {
                ra++;
                r[i] = ra;
            } 
        }
        
       
       reverse(p.begin(), p.end());
        
        int j=0;
        for(int i=0; i<p.size(); i++)
        {
            while(j<ranked.size())
            {
                if(p[i]>=ranked[j])
                {
                    ans.push_back(r[j]);
                    break;
                }else if(j==ranked.size()-1)
                       {
                         ans.push_back(r[j]+1);  
                       }
                j++;
            }
        }
        
        
        reverse(ans.begin(), ans.end());

return ans;
}


// optimal solution  using stack
#include <stack>
#include <iostream>
using namespace std;

int main(){
  unsigned long n, m, i, tmp;
  cin >> n;
  stack<unsigned long> scores;
  for (i = 0; i < n; ++i) {
    cin >> tmp;
    if (scores.empty() || scores.top() != tmp) scores.push(tmp);
  }
  cin >> m;
  for (i = 0; i < m; ++i) {
    cin >> tmp;
    while (!scores.empty() && tmp >= scores.top()) 
    scores.pop();
    
    
    cout << (scores.size() + 1) << endl;
  }
  return 0;
}
