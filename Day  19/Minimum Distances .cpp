//https://www.hackerrank.com/challenges/minimum-distances/problem

int minimumDistances(vector<int> a) {
int minF=1001;
int tempMin =1001;
for(int i=0; i<a.size(); i++)
{
    for(int j=i+1; j<a.size(); j++)
    {
        if(a[i]==a[j])
        {
           tempMin = abs(j-i);
           minF = min(minF, tempMin);
        }
    }
}
if(minF==1001)
{
    return -1;
}


return minF;  
}
