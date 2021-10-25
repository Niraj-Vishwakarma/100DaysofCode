vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
vector<int> ans;
vector<int>rot;
int r = k%a.size();
for(int i=a.size()-r; i<a.size(); i++)
{
    rot.push_back(a[i]);
}
for(int i=0; i<=a.size()-r; i++)
{
    rot.push_back(a[i]);
}
for(int i=0; i<queries.size(); i++)
{
  ans.push_back(rot[queries[i]]); 
}

return ans;
}
