vector<int> cutTheSticks(vector<int> arr) {
vector<int>ans;

sort(arr.begin(),arr.end());
reverse(arr.begin(), arr.end());

while(!arr.empty()){

ans.push_back(arr.size());
for(int i = 0; i<arr.size();++i)
    arr[i]-=arr[arr.size()-1];
while(arr.back() ==0 && !arr.empty())
    arr.pop_back();

    }

return ans;

}
