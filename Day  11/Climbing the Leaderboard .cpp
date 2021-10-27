
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
